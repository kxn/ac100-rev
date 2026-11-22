// func cw_priv_ap_led_op_dump @ 005a51ec size=156

undefined4 cw_priv_ap_led_op_dump(int param_1)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap led op \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap led op (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x \r\n",*piVar3);
  iVar1 = *piVar3;
  if (iVar1 == 0) {
    pcVar2 = "closed";
  }
  else {
    pcVar2 = "open";
  }
  printf("\t\t\t\tap led op: %d(%s) \r\n ",iVar1,pcVar2);
  return 0;
}

