// func cw_priv_stat_prd_dump @ 005c7fbc size=152

undefined4 cw_priv_stat_prd_dump(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private state report period \r\n",(uint)*(ushort *)(param_1 + 0xc)
         ,(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private state report period (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x%08x \r\n",*puVar1,puVar1[1]);
  printf("\t\t\t\tframe report period: %d \r\n",*puVar1);
  printf("\t\t\t\tframe optimize period: %d \r\n",puVar1[1]);
  return 0;
}

