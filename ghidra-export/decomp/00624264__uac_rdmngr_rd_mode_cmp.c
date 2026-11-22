// func _uac_rdmngr_rd_mode_cmp @ 00624264 size=72

bool _uac_rdmngr_rd_mode_cmp(int param_1,char *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    iVar1 = atoi(param_2);
    bVar2 = iVar1 != *(char *)(param_1 + 9);
  }
  return bVar2;
}

