// func update_high_per_ap_chn_info @ 00482dfc size=516

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 update_high_per_ap_chn_info(int param_1,short param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = (int)param_2;
  FUN_004082d0(l_wsta_roam_data,0xffffffff);
  if (wsta_roam_debug_switch != '\0') {
    printf("[WSTA_ROAM_DEBUG]%s()/%d frep = %d, chnl = %d, force_update = %d\n",
           "update_high_per_ap_chn_info",0x494,param_1,iVar2,param_3);
  }
  if (param_1 == 1) {
    if ((param_3 == 1) || (uVar1 = 0xffffffff, (ushort)(high_per_ap_chn_info + 1U) < 2)) {
      if (wsta_roam_debug_switch != '\0') {
        printf("[WSTA_ROAM_DEBUG]%s()/%d update 2g real chnl:%d - %d\n",
               "update_high_per_ap_chn_info",0x499,(int)high_per_ap_chn_info,iVar2);
      }
      uVar1 = 0;
      high_per_ap_chn_info = param_2;
    }
  }
  else if (param_1 == 2) {
    if ((param_3 == 1) || (uVar1 = 0xffffffff, (ushort)(_DAT_0076756e + 1U) < 2)) {
      if (wsta_roam_debug_switch != '\0') {
        printf("[WSTA_ROAM_DEBUG]%s()/%d update 5g1 real chnl:%d - %d\n",
               "update_high_per_ap_chn_info",0x4a2,(int)_DAT_0076756e,iVar2);
      }
      uVar1 = 0;
      _DAT_0076756e = param_2;
    }
  }
  else {
    uVar1 = 0xffffffff;
    if ((param_1 == 3) && ((param_3 == 1 || ((ushort)(DAT_00767570 + 1U) < 2)))) {
      if (wsta_roam_debug_switch != '\0') {
        printf("[WSTA_ROAM_DEBUG]%s()/%d update 5g2 real chnl:%d - %d\n",
               "update_high_per_ap_chn_info",0x4ab,(int)DAT_00767570,iVar2);
      }
      uVar1 = 0;
      DAT_00767570 = param_2;
    }
  }
  FUN_00407f30(l_wsta_roam_data);
  return uVar1;
}

