// func cw_msg_ele_mngr_get @ 00562890 size=92

undefined * cw_msg_ele_mngr_get(uint param_1)

{
  uint uVar1;
  undefined *puVar2;
  
  uVar1 = (param_1 & 0xffff) - 1;
  if (0x35 < (uVar1 & 0xffff)) {
    uVar1 = (param_1 & 0xffff) - 0x400;
    puVar2 = (undefined *)0x0;
    if ((uVar1 & 0xffff) < 0x19) {
      puVar2 = (&PTR_g_cw_msg_ele_80211_add_wlan_mngr_006d2e88)[uVar1];
    }
    return puVar2;
  }
  return (&PTR_g_cw_msg_ele_ac_descriptor_mngr_006d2db0)[uVar1];
}

