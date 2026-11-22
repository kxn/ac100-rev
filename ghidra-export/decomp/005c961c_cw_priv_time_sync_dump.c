// func cw_priv_time_sync_dump @ 005c961c size=152

undefined4 cw_priv_time_sync_dump(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private time sync \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private time sync (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x%08x \r\n",*puVar1,puVar1[1]);
  printf("\t\t\t\ttime stamp: %d \r\n ",*puVar1);
  printf("\t\t\t\ttime threshold: %d \r\n ",puVar1[1]);
  return 0;
}

