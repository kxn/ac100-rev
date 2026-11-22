// func cw_priv_bcast_storm_ctrl_dump @ 005abadc size=176

undefined4 cw_priv_bcast_storm_ctrl_dump(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) private broadcast storm control \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: private broadcast storm control (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%08x... \r\n",(uint)*pbVar2,*(undefined4 *)(pbVar2 + 4));
  if (*pbVar2 == 0) {
    pcVar1 = "disable";
  }
  else {
    pcVar1 = "enable";
  }
  printf("\t\t\t\tState: %02d(%s)... \r\n",(uint)*pbVar2,pcVar1);
  printf("\t\t\t\tRate: %04d... \r\n",*(undefined4 *)(pbVar2 + 4));
  return 0;
}

