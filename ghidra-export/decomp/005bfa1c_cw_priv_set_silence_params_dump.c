// func cw_priv_set_silence_params_dump @ 005bfa1c size=132

undefined4 cw_priv_set_silence_params_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private set ap mode \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private time sync (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\troma_cnt: %d\r\n",(uint)*pbVar1);
  printf("\t\t\tsilence_time: %d\r\n",(uint)*(ushort *)(pbVar1 + 2));
  return 0;
}

