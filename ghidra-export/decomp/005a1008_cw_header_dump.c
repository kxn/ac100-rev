// func cw_header_dump @ 005a1008 size=496

undefined4 cw_header_dump(byte *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (param_1 == (byte *)0x0) {
    return 0xffffffff;
  }
  puts("\tPreamble \r");
  printf("\t\t0000 .... = Version: %d \r\n",(uint)*param_1);
  printf("\t\t.... 0000 = Type: CAPWAP Header (%d) \r\n",(uint)param_1[1]);
  puts("\tHeader \r");
  printf("\t\t0000 0... .... .... .... .... = Header Length: %d \r\n",(uint)param_1[2] << 2);
  printf("\t\t.... .000 00.. .... .... .... = Radio ID: %d \r\n",(uint)param_1[3]);
  if (param_1[4] == 1) {
    uVar2 = 1;
    pcVar1 = "\t\t.... .... ..00 000. .... .... = Wireless Binding ID: IEEE 802.11 (%d) \r\n";
  }
  else {
    if (param_1[4] != 3) goto LAB_005a109c;
    uVar2 = 3;
    pcVar1 = "\t\t.... .... ..00 000. .... .... = Wireless Binding ID: EPCGlobal (%d) \r\n";
  }
  printf(pcVar1,uVar2);
LAB_005a109c:
  puts("\t\t.... .... .... ...0 0000 0000 = Header Flags \r");
  if (param_1[5] == 0) {
    pcVar1 = 
    "\t\t\t.... .... .... ...0 .... .... = Payload Type: the payload is an IEEE 802.3 frame \r";
  }
  else {
    pcVar1 = 
    "\t\t\t.... .... .... ...1 .... .... = Payload Type: Native frame format (see Wireless Binding ID field) \r"
    ;
  }
  puts(pcVar1);
  if (param_1[6] == 0) {
    pcVar1 = "\t\t\t.... .... .... .... 0... .... = Fragment: Don\'t Fragment \r";
  }
  else {
    pcVar1 = "\t\t\t.... .... .... .... 1... .... = Fragment: Fragmented \r";
  }
  puts(pcVar1);
  if (param_1[7] == 0) {
    pcVar1 = "\t\t\t.... .... .... .... .0.. .... = Last Fragment: More fragments follow \r";
  }
  else {
    pcVar1 = "\t\t\t.... .... .... .... .1.. .... = Last Fragment: This is the last fragment \r";
  }
  puts(pcVar1);
  if (param_1[8] == 0) {
    pcVar1 = 
    "\t\t\t.... .... .... .... ..0. .... = Wireless header: Wireless Specific Information \r";
  }
  else {
    pcVar1 = 
    "\t\t\t.... .... .... .... ..1. .... = Wireless header: No Wireless Specific Information \r";
  }
  puts(pcVar1);
  if (param_1[9] == 0) {
    pcVar1 = "\t\t\t.... .... .... .... ...0 .... = Radio MAC header: Radio MAC Address \r";
  }
  else {
    pcVar1 = "\t\t\t.... .... .... .... ...1 .... = Radio MAC header: No Radio MAC Address \r";
  }
  puts(pcVar1);
  if (param_1[10] == 0) {
    pcVar1 = "\t\t\t.... .... .... .... .... 0... = Keep-Alive: No Keep-Alive \r";
  }
  else {
    pcVar1 = "\t\t\t.... .... .... .... .... 1... = Keep-Alive: Keep-Alive \r";
  }
  puts(pcVar1);
  uVar2 = 0xffffffff;
  if (param_1[0xb] == 0) {
    puts("\t\t\t.... .... .... .... .... .000 = Reserved: Not set \r");
    printf("\t\tFragment ID: %d \r\n",(uint)*(ushort *)(param_1 + 0xc));
    printf("\t\t0000 0000 0000 0... = Fragment Offset: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
    puts("\t\t.... .... .... .000 = Reserved: 0 \r");
    uVar2 = 0;
  }
  return uVar2;
}

