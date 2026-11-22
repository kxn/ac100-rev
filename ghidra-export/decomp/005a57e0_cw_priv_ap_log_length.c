// func cw_priv_ap_log_length @ 005a57e0 size=76

short cw_priv_ap_log_length(ushort *param_1)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  sVar2 = 0;
  if (param_1 != (ushort *)0x0) {
    iVar3 = *(int *)(param_1 + 2);
    sVar2 = 2;
    if (iVar3 != 0) {
      for (iVar4 = 0; iVar4 < (int)(uint)*param_1; iVar4 = iVar4 + 1) {
        psVar1 = (short *)(iVar3 + 2);
        iVar3 = iVar3 + 8;
        sVar2 = sVar2 + *psVar1 + 4;
      }
    }
  }
  return sVar2;
}

