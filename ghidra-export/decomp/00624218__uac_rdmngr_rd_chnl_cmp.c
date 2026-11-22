// func _uac_rdmngr_rd_chnl_cmp @ 00624218 size=76

bool _uac_rdmngr_rd_chnl_cmp(int param_1,char *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    iVar1 = atoi(param_2);
    bVar2 = *(short *)(param_1 + 0xc) != (short)iVar1;
  }
  return bVar2;
}

