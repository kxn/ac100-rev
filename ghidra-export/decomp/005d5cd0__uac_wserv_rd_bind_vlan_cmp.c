// func _uac_wserv_rd_bind_vlan_cmp @ 005d5cd0 size=132

bool _uac_wserv_rd_bind_vlan_cmp(undefined4 param_1,undefined4 param_2,char *param_3)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  ushort local_20 [6];
  
  bVar3 = true;
  local_20[0] = 0;
  if (param_3 != (char *)0x0) {
    uVar1 = atoi(param_3);
    iVar2 = wserv_db_rd_get_bind_vlan_by_wserv_id(param_2,param_1,local_20);
    if (iVar2 == 0) {
      bVar3 = (uint)local_20[0] != (uVar1 & 0xffff);
    }
  }
  return bVar3;
}

