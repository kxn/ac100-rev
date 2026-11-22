// func _stats_rd_enable_cb @ 00672d08 size=120

undefined4 _stats_rd_enable_cb(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = rdmngr_db_generate_ap_id();
  uVar1 = uVar1 & 0xffff;
  iVar2 = apmngr_db_get_ap_max();
  if (iVar2 <= (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    if ((int)uVar1 < iVar2 + iVar3) {
      return 0;
    }
  }
  stats_db_radio_active(uVar1,param_1 & 0xf,0);
  return 0;
}

