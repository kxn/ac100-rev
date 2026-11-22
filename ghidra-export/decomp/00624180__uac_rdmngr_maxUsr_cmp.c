// func _uac_rdmngr_maxUsr_cmp @ 00624180 size=76

bool _uac_rdmngr_maxUsr_cmp(int param_1,char *param_2)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = true;
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    uVar1 = atoi(param_2);
    bVar2 = (uint)*(ushort *)(param_1 + 0x1a) != (uVar1 & 0xffff);
  }
  return bVar2;
}

