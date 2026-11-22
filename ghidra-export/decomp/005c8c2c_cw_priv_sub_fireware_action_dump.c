// func cw_priv_sub_fireware_action_dump @ 005c8c2c size=148

undefined4 cw_priv_sub_fireware_action_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private sub fireware action \r\n",(uint)*(ushort *)(param_1 + 0xc)
         ,(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private sub fireware action (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\ttype: %d\r\n",(uint)*pbVar1);
  printf("\t\t\t\tfile_num: %d\r\n",(uint)pbVar1[1]);
  printf("\t\t\t\tresult: %d\r\n",*(undefined4 *)(pbVar1 + 4));
  return 0;
}

