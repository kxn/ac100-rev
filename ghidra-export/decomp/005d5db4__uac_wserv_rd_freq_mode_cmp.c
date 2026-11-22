// func _uac_wserv_rd_freq_mode_cmp @ 005d5db4 size=80

bool _uac_wserv_rd_freq_mode_cmp(undefined4 param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = true;
  if (param_3 != (char *)0x0) {
    iVar1 = atoi(param_3);
    iVar2 = rdmngr_db_get_rd_freq_mode(param_2);
    bVar3 = iVar1 != iVar2;
  }
  return bVar3;
}

