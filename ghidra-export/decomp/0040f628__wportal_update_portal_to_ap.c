// func _wportal_update_portal_to_ap @ 0040f628 size=348

undefined4 _wportal_update_portal_to_ap(int param_1,int param_2)

{
  int iVar1;
  int local_148;
  int local_144;
  undefined4 *local_140;
  undefined4 *local_13c;
  undefined4 local_138;
  char acStack_134 [128];
  undefined4 local_b4;
  char acStack_b0 [128];
  undefined1 local_30;
  undefined1 auStack_2c [12];
  
  memset(&local_138,0,0x84);
  local_138 = *(undefined4 *)(param_1 + 0x134);
  snprintf(acStack_134,0x80,"http://192.168.1.253:%d/wportal/?pagetype=%d",g_portal_port,100);
  memset(&local_b4,0,0x94);
  snprintf(acStack_b0,0x80,"http://192.168.1.253:%d/wportal/?pagetype=%d",g_portal_port,100);
  local_b4 = *(undefined4 *)(param_1 + 0x134);
  local_30 = 0xff;
  FUN_0051ad88(auStack_2c);
  local_144 = param_2 + 0x17;
  local_148 = param_2;
  local_140 = &local_138;
  local_13c = &local_b4;
  if (wportal_info_switch == 0) {
    iVar1 = *(int *)(param_1 + 0x134);
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x134);
    }
    else {
      printf("[WPORTAL_INFO]%s()/%d Add rdt entry: %s vlan: %d\n\n","_wportal_update_portal_to_ap",
             0x4c5,acStack_134,local_138);
      iVar1 = *(int *)(param_1 + 0x134);
    }
  }
  if (iVar1 == 0xfff) {
    iVar1 = 0;
  }
  uac_wservice_for_each_ap_bind_vlan(iVar1,_wportal_update_wportal_cb,&local_148);
  return 0;
}

