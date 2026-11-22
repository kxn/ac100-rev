// func _wsta_roam_free_pmk @ 00480cfc size=160

void _wsta_roam_free_pmk(void *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00407f40(DAT_0076754c,param_1);
  if ((iVar1 != 0) && (wsta_roam_err_switch != '\0')) {
    printf("[WSTA_ROAM_ERROR]%s()/%d uac_hash_remove() fail, roam_pmk_entry->id=%d, ret = %d!\n",
           "_wsta_roam_free_pmk",0xd2,*(undefined4 *)((int)param_1 + 4),iVar1);
  }
  FUN_004080f0(DAT_00767544,*(undefined4 *)((int)param_1 + 4));
  memset(param_1,0,0x4c);
  DAT_00767550 = DAT_00767550 + -1;
  return;
}

