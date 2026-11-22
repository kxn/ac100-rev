// func apdb_init @ 0060687c size=1116

undefined4 apdb_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  system("touch /tmp/apdb_care_sale_method >/dev/null 2>&1");
  l_apdb_mutex = FUN_00407f00("apdb_mutex",1);
  if (l_apdb_mutex == 0) {
    if (apdb_err_switch == 0) goto LAB_00606940;
    __format = "[APDB_ERROR]%s()/line %d : Failed to init mutex.\n";
    uVar2 = 0x20a8;
  }
  else {
    vendor_type = FUN_00408080();
    if (vendor_type == 3) {
      if (apdb_err_switch == 0) goto LAB_00606940;
      __format = "[APDB_ERROR]%s()/line %d : get vendor failed.\n";
      uVar2 = 0x20af;
    }
    else {
      iVar1 = FUN_00408210(&sales_method,0x21);
      if (iVar1 == -1) {
        if (apdb_err_switch == 0) goto LAB_00606940;
        __format = "[APDB_ERROR]%s()/line %d : get sales method failed.\n";
        uVar2 = 0x20b6;
      }
      else {
        iVar1 = FUN_004084c0(&extra_sales_methods,5,&extra_sales_method_count);
        if (iVar1 == -1) {
          if (apdb_err_switch == 0) goto LAB_00606940;
          __format = "[APDB_ERROR]%s()/line %d : get extra sales method failed.\n";
          uVar2 = 0x20bc;
        }
        else {
          FUN_0051ad88(&l_apdb_callback_list);
          iVar1 = FUN_006017e4();
          if (iVar1 == -1) {
            if (apdb_err_switch == 0) goto LAB_00606940;
            __format = "[APDB_ERROR]%s()/line %d : load apdb failed.\n";
            uVar2 = 0x20c6;
          }
          else {
            if (apdb_debug_switch != 0) {
              printf("[APDB_DEBUG]%s()/line %d : load apdb success.\n","apdb_init",0x20c9);
            }
            iVar1 = _apdb_load_finish();
            if (iVar1 == -1) {
              if (apdb_err_switch == 0) goto LAB_00606940;
              __format = "[APDB_ERROR]%s()/line %d : copy apdb after loading failed.\n";
              uVar2 = 0x20ce;
            }
            else {
              iVar1 = FUN_006038e0();
              if (iVar1 == -1) {
                if (apdb_err_switch == 0) goto LAB_00606940;
                __format = "[APDB_ERROR]%s()/line %d : load apdb failed.\n";
                uVar2 = 0x20d6;
              }
              else {
                if (apdb_debug_switch != 0) {
                  printf("[APDB_DEBUG]%s()/line %d : load nego apdb success.\n","apdb_init",0x20d9);
                }
                iVar1 = _apdb_init_unsupported_ap_list();
                if (iVar1 == -1) {
                  if (apdb_err_switch == 0) goto LAB_00606940;
                  __format = "[APDB_ERROR]%s()/line %d : load apdb failed.\n";
                  uVar2 = 0x20df;
                }
                else {
                  iVar1 = FUN_004084d0("unsupport_ap_get",3,_apdb_jcs_callback_get_unsupport_ap);
                  if ((iVar1 != 0) && (apdb_err_switch != 0)) {
                    printf("[APDB_ERROR]%s()/line %d : register _apdb_jcs_callback_file_check failed.\n"
                           ,"_apdb_jcs_callback_init",0x1461);
                  }
                  iVar1 = FUN_004084d0("aplist_get",3,_apdb_jcs_callback_get_aplist);
                  if ((iVar1 != 0) && (apdb_err_switch != 0)) {
                    printf("[APDB_ERROR]%s()/line %d : register _apdb_jcs_callback_get_aplist failed.\n"
                           ,"_apdb_jcs_callback_init",0x1467);
                  }
                  iVar1 = FUN_004084d0("nego_del",1,_apdb_jcs_callback_del_all_negotiation);
                  if ((iVar1 != 0) && (apdb_err_switch != 0)) {
                    printf("[APDB_ERROR]%s()/line %d : register _apdb_jcs_callback_del_all_negotiation failed.\n"
                           ,"_apdb_jcs_callback_init",0x146d);
                  }
                  iVar1 = FUN_004084d0("apdb_datasync",2,_apdb_jcs_callback_datasync);
                  if ((iVar1 != 0) && (apdb_err_switch != 0)) {
                    printf("[APDB_ERROR]%s()/line %d : register _apdb_jcs_callback_datasync failed.\n"
                           ,"_apdb_jcs_callback_init",0x1473);
                  }
                  FUN_00408620("/etc/nouci_config/dbs/apdb_nego.db",_apdb_nego_db_manage_num_get);
                  iVar1 = apdb_pkt_init();
                  if (iVar1 == -1) {
                    if (apdb_err_switch == 0) goto LAB_00606940;
                    __format = "[APDB_ERROR]%s()/line %d : apdb_pkt_init failed.\n";
                    uVar2 = 0x20f1;
                  }
                  else {
                    g_stat = 0;
                    DAT_007cc2b0 = 0;
                    iVar1 = apdb_sync_init();
                    if (iVar1 != -1) {
                      apdb_debug_init();
                      if (apdb_debug_switch == 0) {
                        return 0;
                      }
                      printf("[APDB_DEBUG]%s()/line %d : init apdb success\n","apdb_init",0x2105);
                      return 0;
                    }
                    if (apdb_err_switch == 0) goto LAB_00606940;
                    __format = "[APDB_ERROR]%s()/line %d : apdb_sync_init failed.\n";
                    uVar2 = 0x2100;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  printf(__format,"apdb_init",uVar2);
LAB_00606940:
  _apdb_free_all_db();
  if (l_apdb_mutex != 0) {
    FUN_00408360();
    l_apdb_mutex = 0;
  }
  return 0xffffffff;
}

