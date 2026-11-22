// func audit_client_db_init @ 0050a640 size=388

undefined4 audit_client_db_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined8 uVar3;
  
  FUN_0051ad88(&audit_msg_queue);
  DAT_00768910 = FUN_00407dc0(_audit_client_db_sniffing_sort_func,
                              _audit_client_db_sniffing_compare_func,
                              _audit_client_db_sniffing_destroy_func);
  if (DAT_00768910 == 0) {
    if (audit_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[AUDIT_ERR]%s()/%d Create sniffing tree failed.\n";
    uVar2 = 0x173;
  }
  else {
    DAT_00768914 = 0xffffffff;
    DAT_00768918 = 0xffffffff;
    iVar1 = pipe(&DAT_00768914);
    if (iVar1 == 0) {
      DAT_0076891c = FUN_00407f00("audit_msg",1);
      if (DAT_0076891c == 0) {
        if (audit_err_switch == 0) {
          DAT_0076891c = 0;
          return 0xffffffff;
        }
        __format = "[AUDIT_ERR]%s()/%d Create database mutex failed.\n";
        uVar2 = 0x182;
      }
      else {
        uVar2 = wsta_profile_get_max_wstation();
        uVar3 = __floatunsidf(uVar2);
        uVar3 = __muldf3((int)((ulonglong)uVar3 >> 0x20),(int)uVar3,0x40040000,0);
        g_msg_max = __fixdfsi((int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
        iVar1 = _audit_client_db_gloabal_config_read();
        if (iVar1 != -1) {
          return 0;
        }
        if (audit_err_switch == 0) {
          return 0xffffffff;
        }
        __format = "[AUDIT_ERR]%s()/%d Read global config failed.\n";
        uVar2 = 0x18a;
      }
    }
    else {
      if (audit_err_switch == 0) {
        return 0xffffffff;
      }
      __format = "[AUDIT_ERR]%s()/%d packet queue pipe create failed.\n";
      uVar2 = 0x17b;
    }
  }
  printf(__format,"audit_client_db_init",uVar2);
  return 0xffffffff;
}

