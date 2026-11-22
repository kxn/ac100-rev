// func _uac_arp_defend_bind_arp_num_cmp @ 00473008 size=124

bool _uac_arp_defend_bind_arp_num_cmp(undefined4 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  bVar3 = true;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if (param_2 != (char *)0x0) {
    iVar1 = atoi(param_2);
    iVar2 = arp_defend_db_ap_entry_get(param_1,&local_20);
    if (iVar2 == 0) {
      bVar3 = local_18 != iVar1;
    }
  }
  return bVar3;
}

