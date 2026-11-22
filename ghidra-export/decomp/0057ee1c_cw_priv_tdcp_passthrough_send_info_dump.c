// func cw_priv_tdcp_passthrough_send_info_dump @ 0057ee1c size=216

undefined4 cw_priv_tdcp_passthrough_send_info_dump(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private passthrough send information \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private passthrough send information(%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x... \r\n",*puVar1);
  printf("\t\t\t\tid: %d \r\n",*puVar1);
  printf("\t\t\t\tdata len: %d \r\n",puVar1[1]);
  printf("\t\t\t\tdata need_result: %d \r\n",(uint)*(byte *)(puVar1 + 2));
  if ((puVar1[3] == 0) || (puVar1[1] == 0)) {
    puts("\t\t\t\tdata: is null \r");
  }
  else {
    printf("\t\t\t\tdata:%s\r\n");
  }
  return 0;
}

