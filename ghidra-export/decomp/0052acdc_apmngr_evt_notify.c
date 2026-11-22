// func apmngr_evt_notify @ 0052acdc size=156

undefined4 apmngr_evt_notify(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d Triger a %s event.\n","apmngr_evt_notify",0x1da,
           (&apmngr_evt_str)[param_1]);
  }
  if (param_2 != 0) {
    uVar1 = apmngr_callback_proc(param_1,param_2);
    return uVar1;
  }
  return 0xffffffff;
}

