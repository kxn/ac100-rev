// func _uac_rdmngr_rd_state_cmp @ 00624130 size=80

bool _uac_rdmngr_rd_state_cmp(int param_1,char *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    iVar1 = strcasecmp(param_2,"on");
    bVar2 = (uint)(iVar1 == 0) != (int)*(char *)(param_1 + 0x48);
  }
  return bVar2;
}

