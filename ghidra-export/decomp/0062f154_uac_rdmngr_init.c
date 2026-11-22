// func uac_rdmngr_init @ 0062f154 size=380

undefined4 uac_rdmngr_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = rdmngr_db_init();
  if (iVar1 == 0) {
    iVar1 = rdmngr_init();
    if (iVar1 == 0) {
      iVar1 = uac_rdmngr_recover_rdentry();
      if (iVar1 == 0) {
        iVar1 = uac_rdmngr_jcs_register();
        if (iVar1 == 0) {
          system(
                "ubus call cloudclient register_cmd_callback \'{\"register_notify_cmd\":\"echo 8\",\"wait_time\":0,\"type\":\"feature\",\"action\":\"add\"}\' &> /dev/null"
                );
          apmngr_support_capacity_register(1);
          apmngr_support_capacity_register(9);
          apmngr_support_capacity_register(10);
          apmngr_support_capacity_register(0x15);
          apmngr_support_capacity_register(0x26);
          apmngr_support_capacity_register(0x39);
          return 0;
        }
        if (rdmngr_err_switch != 0) {
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          __format = "[RDMNGR_ERROR]%s()/%d uac_rdmngr_jcs_register() error.\n";
          uVar2 = 0xa7d;
          goto LAB_0062f1dc;
        }
      }
      else if (rdmngr_err_switch != 0) {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[RDMNGR_ERROR]%s()/%d uac_rdmngr_recover_rdentry() error.\n";
        uVar2 = 0xa78;
LAB_0062f1dc:
        printf(__format,"uac_rdmngr_init",uVar2);
        return 0xffffffff;
      }
    }
    else if (rdmngr_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[RDMNGR_ERROR]%s()/%d rdmngr_init() error.\n";
      uVar2 = 0xa73;
      goto LAB_0062f1dc;
    }
  }
  else if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    __format = "[RDMNGR_ERROR]%s()/%d rdmngr_db_init() error.\n";
    uVar2 = 0xa6d;
    goto LAB_0062f1dc;
  }
  return 0xffffffff;
}

