// func cw_maximum_message_length_dump @ 00577d8c size=132

undefined4 cw_maximum_message_length_dump(int param_1)

{
  ushort *puVar1;
  
  puVar1 = *(ushort **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Maximum Message Length \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Maximum Message Length (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %04x \r\n",(uint)*puVar1);
  printf("\t\t\tMaximum Message Length: %d \r\n",(uint)*puVar1);
  return 0;
}

