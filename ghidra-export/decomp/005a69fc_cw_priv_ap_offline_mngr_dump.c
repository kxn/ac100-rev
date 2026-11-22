// func cw_priv_ap_offline_mngr_dump @ 005a69fc size=172

undefined4 cw_priv_ap_offline_mngr_dump(int param_1)

{
  char *pcVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap offline mngr \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap offline mngr (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x... \r\n",*piVar2);
  if (*piVar2 == 0) {
    pcVar1 = "closed";
  }
  else {
    pcVar1 = "open";
  }
  printf("\t\t\t\tap offline mngr status: %u(%s) \r\n ",*piVar2,pcVar1);
  printf("\t\t\t\trssi inform interval: %u \r\n ",piVar2[1]);
  return 0;
}

