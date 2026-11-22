// func cw_priv_11ax_feature_default_value_dump @ 005a231c size=228

undefined4 cw_priv_11ax_feature_default_value_dump(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private rate \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: 11ax default value (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tdownlink_mumimo: %d \r\n",(uint)*(byte *)(iVar1 + 1));
  printf("\t\t\t\tuplink_mimimo: %d \r\n",(uint)*(byte *)(iVar1 + 2));
  printf("\t\t\t\tdownlink_ofdma: %d \r\n",(uint)*(byte *)(iVar1 + 3));
  printf("\t\t\t\tuplink_ofdma: %d \r\n",(uint)*(byte *)(iVar1 + 4));
  printf("\t\t\t\ttwt: %d \r\n",(uint)*(byte *)(iVar1 + 4));
  printf("\t\t\t\tgi_mode: %d \r\n",(uint)*(byte *)(iVar1 + 6));
  printf("\t\t\t\t_6g_enable: %d \r\n",(uint)*(byte *)(iVar1 + 7));
  printf("\t\t\t\t_6g_psc_enable: %d \r\n",(uint)*(byte *)(iVar1 + 8));
  return 0;
}

