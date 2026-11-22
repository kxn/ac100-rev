// func _uac_rdmngr_bw_mode_cmp @ 006241cc size=76

bool _uac_rdmngr_bw_mode_cmp(int param_1,char *param_2)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = true;
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    uVar1 = atoi(param_2);
    bVar2 = (uint)*(byte *)(param_1 + 10) != (uVar1 & 0xff);
  }
  return bVar2;
}

