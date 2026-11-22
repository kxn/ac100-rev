// func cw_priv_sub_device_report_dump @ 005c868c size=216

undefined4 cw_priv_sub_device_report_dump(int param_1)

{
  ushort *puVar1;
  
  puVar1 = *(ushort **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private sub device report information \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private sub device report information(%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x... \r\n",(uint)*puVar1);
  printf("\t\t\t\ttype: %d \r\n",(uint)*puVar1);
  printf("\t\t\t\tcom_encrypted: %d \r\n",(uint)puVar1[1]);
  printf("\t\t\t\tlen: %d \r\n",*(undefined4 *)(puVar1 + 2));
  if ((*(int *)(puVar1 + 4) == 0) || (*(int *)(puVar1 + 2) == 0)) {
    puts("\t\t\t\tdata: is null \r");
  }
  else {
    printf("\t\t\t\tdata:%s\r\n");
  }
  return 0;
}

