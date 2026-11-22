// func _uac_wserv_rd_bind_status_cmp @ 005d5d54 size=96

bool _uac_wserv_rd_bind_status_cmp(undefined4 param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = true;
  if (param_3 != (char *)0x0) {
    iVar1 = atoi(param_3);
    iVar2 = wserv_db_is_wserv_bind_to_rd(param_2,param_1);
    bVar3 = iVar1 != iVar2;
  }
  return bVar3;
}

