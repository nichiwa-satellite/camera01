#include <project.h>
#include <stdio.h>
uint8 rec;
uint8 get[]            ={0x56, 0x00, 0x11, 0x00};
uint8 reset_camera[]    =  { 0x56, 0x00, 0x26, 0x00 };
uint8 baurate[]         =  { 0x56, 0x00, 0x24, 0x16, 0x01, 0x2A, 0xF2 };
uint8 config_datasize[] =  { 0x56, 0x00, 0x31, 0x05, 0x04, 0x01, 0x00, 0x19, 0x00 };    //640×480
uint8 take_picture[]    =  { 0x56, 0x00, 0x36, 0x01, 0x00 };
uint8 read_datasize[]   =  { 0x56, 0x00, 0x34, 0x01, 0x00 };
uint8 load_data[]       =  { 0x56, 0x00, 0x32, 0x0C, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCA, 0x6C, 0x00, 0xFF };

CY_ISR_PROTO(isr_tx1);
CY_ISR_PROTO(isr_tx2);
CY_ISR_PROTO(isr_rx1);
CY_ISR_PROTO(isr_rx2);

int main()
{
    char  str;
    char log[] = "TXDA 0000\r\n";
    char snd[64];
    char recv;
UART_1_Start();
UART_2_Start();
isr_rx1_StartEx(isr_rx1 );
CyGlobalIntEnable;// Parameter pointer  
while(1){

//UART_1_PutArray(reset_camera,4);
            str=0x00;
            str = UART_2_GetChar();

            if(str == 0x00 || str == 0x30 || str == 0x0D || str == 0x0A){
            //UART_1_PutChar(strPtr);
           // }
                continue;
            }
            if(str != 0x4F && str != 0x4B && str != 0x4E &&  str != 0x47){
//sprintf(snd,"TXDA %x\r\n",str);
//UART_2_PutString(snd);
//UART_2_PutString(log);
CyDelay(100);
UART_2_PutString("TXDA 1111\r\n");
//CyDelay(500);
CyDelay(100);
UART_1_PutArray(config_datasize,9);
//UART_2_PutString("TXDA 2222\r\n");

//UART_2_PutString(log);
//recv = UART_1_GetChar();
//sprintf(snd,"TXDA 3333%c\r\n",recv);
//UART_2_PutString(snd);
CyDelay(100);
UART_2_PutString("TXDA 2222\r\n");
//CyDelay(300);
CyDelay(100);
UART_1_PutArray(take_picture,5);
CyDelay(100);
UART_2_PutString("TXDA 3333\r\n");
//UART_2_PutString(log);
//recv = UART_1_GetChar();
//sprintf(snd,"TXDA 4444%c\r\n",recv);
//UART_2_PutString(snd);
CyDelay(100);
//CyDelay(300);
UART_1_PutArray(read_datasize,5);
CyDelay(100);
UART_2_PutString("TXDA 4444\r\n");
//recv = UART_1_GetChar();
//sprintf(snd,"TXDA 030%c\r\n",recv);
//UART_2_PutString(snd);

//CyDelay(500);
CyDelay(100);
UART_1_PutArray(load_data,16);
CyDelay(100);
UART_2_PutString("TXDA 5555\r\n");


            }
}
}

#pragma interrupt_handler isr_rx1
CY_ISR(isr_rx1)
{
 char recv_data;
 char rec[20] = {0};
 //recv_data = UART_1_GetChar(); // read UART
//UART_2_PutString("TXDA 8888\r\n");
//sprintf(rec,"TXDA 03%c\r\n",recv_data); 

//CyDelay(1000);
//UART_2_PutString(rec);

//CyDelay(1000);
//UART_2_PutString("TXDA 9999\r\n");
//UART_2_PutChar(rec); // echo
}
