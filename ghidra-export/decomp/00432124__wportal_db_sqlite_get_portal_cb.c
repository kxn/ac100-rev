// func _wportal_db_sqlite_get_portal_cb @ 00432124 size=1920

undefined4
_wportal_db_sqlite_get_portal_cb(undefined4 param_1,int param_2,int *param_3,undefined4 *param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  void *__src;
  undefined4 uVar4;
  char *__dest;
  char *__src_00;
  size_t __n;
  char *__s1;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  size_t local_708;
  char local_704 [8];
  char acStack_6fc [32];
  char acStack_6dc [104];
  char acStack_674 [104];
  char acStack_60c [104];
  char acStack_5a4 [128];
  char acStack_524 [128];
  char acStack_4a4 [128];
  char local_424 [128];
  undefined1 auStack_3a4 [128];
  undefined1 auStack_324 [128];
  char acStack_2a4 [52];
  uint local_270 [8];
  int local_250;
  int local_24c;
  int local_248;
  undefined4 local_244;
  uint local_23c;
  undefined1 auStack_238 [520];
  uint local_30;
  int local_2c;
  
  bVar1 = false;
  iVar9 = 0;
  iVar8 = 0;
  iVar7 = 0;
  uVar6 = 0xffffffff;
  uVar5 = 0;
  memset(acStack_60c,0,0x65);
  memset(local_424,0,0x80);
  memset(acStack_4a4,0,0x80);
  memset(acStack_524,0,0x80);
  memset(acStack_5a4,0,0x80);
  memset(acStack_674,0,0x65);
  memset(acStack_6dc,0,0x65);
  memset(acStack_6fc,0,0x20);
  local_708 = 0;
  local_704[0] = '\0';
  local_704[1] = '\0';
  local_704[2] = '\0';
  local_704[3] = '\0';
  local_704[4] = 0;
  memset(auStack_238,0,0x205);
  memset(acStack_6fc,0,0x20);
  local_2c = 0;
  local_30 = 0;
  do {
    if (param_2 <= iVar9) {
      if (bVar1) {
        FUN_00407ec0(local_2c,g_invalid_portal_entry_id,&g_invalid_portal_entry_id_pos);
        uVar4 = 0;
      }
      else {
        iVar9 = wportal_get_mode();
        if (((iVar9 != 1) || (uVar4 = 1, uVar5 != 0)) && (uVar4 = 0, local_30 != 0)) {
          memset(auStack_3a4,0,0x16c);
          local_248 = iVar7;
          iVar9 = wportal_get_mode();
          if (((iVar9 != 1) && (iVar9 = wportal_get_mode(), uVar5 = uVar6, iVar9 != 0)) &&
             (iVar9 = wportal_get_mode(), uVar5 = local_270[0], iVar9 == 2)) {
            strncpy((char *)local_270,acStack_6fc,0x20);
            uVar5 = local_270[0];
          }
          local_270[0] = uVar5;
          iVar9 = strcmp(local_704,"off");
          local_23c = (uint)(iVar9 != 0);
          wserv_db_entry_set_ssid_portal_switch(local_270[0] & 0xff,local_23c);
          if (local_424[0] != '\0') {
            local_250 = iVar8;
            memcpy(auStack_3a4,local_424,0x80);
          }
          if (iVar7 == 0x10) {
            local_24c = iVar8 + 1;
            memcpy(auStack_324,acStack_4a4,0x80);
          }
          else if (iVar7 == 0x20) {
            local_24c = iVar8 + 1;
            __src = (void *)wportal_url_get_domain(acStack_524,&local_708);
            memcpy(auStack_324,__src,local_708);
            strncpy(acStack_2a4,acStack_674,0x31);
            iVar8 = strcmp(acStack_6dc,"local");
            local_244 = 0;
            if (iVar8 != 0) {
              iVar8 = strcmp(acStack_6dc,"remote");
              local_244 = 1;
              if (iVar8 != 0) {
                iVar8 = strcmp(acStack_6dc,"tmp");
                local_244 = 99;
                if (iVar8 != 0) {
                  local_244 = 0xffffffff;
                }
              }
            }
          }
          else if (iVar7 == 0x40) {
            local_24c = iVar8 + 1;
            memcpy(auStack_324,acStack_5a4,0x80);
            wportal_update_cloud_portal_url(acStack_5a4);
          }
          iVar8 = wportal_get_mode();
          if (iVar8 == 1) {
            if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
              printf("[WPORTAL_DBG]%s()/%d Add rdt entry for vlan: %d\n\n",
                     "_wportal_db_sqlite_get_portal_cb",0x36e,local_270[0]);
            }
            wportal_db_rdt_add(auStack_3a4);
            uVar4 = 0;
          }
          else {
            iVar8 = wportal_get_mode();
            if (iVar8 == 0) {
              if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
                printf("[WPORTAL_DBG]%s()/%d Add rdt entry for ssid: %d\n\n",
                       "_wportal_db_sqlite_get_portal_cb",0x373,local_270[0]);
              }
              wportal_db_ssid_rdt_add(auStack_3a4);
              uVar4 = 0;
            }
            else {
              iVar8 = wportal_get_mode();
              uVar4 = 0;
              if (iVar8 == 2) {
                if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
                  printf("[WPORTAL_DBG]%s()/%d Add rdt entry for ssid: %s\n\n",
                         "_wportal_db_sqlite_get_portal_cb",0x378,local_270);
                }
                wportal_db_iface_add(auStack_3a4);
                uVar4 = 0;
              }
            }
          }
        }
      }
      return uVar4;
    }
    __s1 = (char *)*param_4;
    if (__s1 == (char *)0x0) {
      return 1;
    }
    iVar2 = strcmp(__s1,"enable");
    if ((iVar2 == 0) && ((char *)*param_3 != (char *)0x0)) {
      iVar2 = strcmp((char *)*param_3,"on");
      local_30 = (uint)(iVar2 == 0);
    }
    else {
      iVar2 = strcmp(__s1,"entry_id");
      if ((iVar2 == 0) && ((char *)*param_3 != (char *)0x0)) {
        local_2c = atoi((char *)*param_3);
      }
      else {
        iVar2 = strcmp(__s1,"jump_page_name");
        if (iVar2 == 0) {
          __src_00 = (char *)*param_3;
          __dest = acStack_60c;
          if (__src_00 == (char *)0x0) goto LAB_004322f0;
LAB_004322d8:
          __n = 100;
LAB_004322dc:
          strncpy(__dest,__src_00,__n);
        }
        else {
LAB_004322f0:
          iVar2 = strcmp(__s1,"vlan_id");
          if ((iVar2 == 0) && ((char *)*param_3 != (char *)0x0)) {
            uVar3 = atoi((char *)*param_3);
            uVar5 = 0xfff;
            if (uVar3 != 0) {
              uVar5 = uVar3;
            }
          }
          else {
            iVar2 = strcmp(__s1,"serv_id");
            if ((iVar2 == 0) && ((char *)*param_3 != (char *)0x0)) {
              uVar6 = atoi((char *)*param_3);
              if ((((uVar6 != 0xffffffff) &&
                   (iVar2 = wserv_db_get_entry_by_id(uVar6,auStack_238), iVar2 != 0)) &&
                  (bVar1 = true, wportal_err_switch != 0)) &&
                 (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[WPORTAL_ERR]%s()/%d wserv_id=%d is invalid.\n",
                       "_wportal_db_sqlite_get_portal_cb",0x2f3,uVar6);
              }
            }
            else {
              iVar2 = strcmp(__s1,"fail_url");
              if (iVar2 == 0) {
                __src_00 = (char *)*param_3;
                __dest = local_424;
                if (__src_00 == (char *)0x0) goto LAB_004323c4;
LAB_00432458:
                __n = 0x7f;
                goto LAB_004322dc;
              }
LAB_004323c4:
              iVar2 = strcmp(__s1,"fail_id");
              if ((iVar2 == 0) && ((char *)*param_3 != (char *)0x0)) {
                iVar8 = atoi((char *)*param_3);
              }
              else {
                iVar2 = strcmp(__s1,"auth_type");
                if ((iVar2 == 0) && ((char *)*param_3 != (char *)0x0)) {
                  iVar7 = atoi((char *)*param_3);
                }
                else {
                  iVar2 = strcmp(__s1,"remote_url");
                  if (iVar2 == 0) {
                    __src_00 = (char *)*param_3;
                    __dest = acStack_4a4;
                    if (__src_00 != (char *)0x0) goto LAB_00432458;
                  }
                  iVar2 = strcmp(__s1,"cmcc_url");
                  if (iVar2 == 0) {
                    __src_00 = (char *)*param_3;
                    __dest = acStack_524;
                    if (__src_00 != (char *)0x0) goto LAB_00432458;
                  }
                  iVar2 = strcmp(__s1,"cmcc_ac_name");
                  if (iVar2 == 0) {
                    __src_00 = (char *)*param_3;
                    __dest = acStack_674;
                    if (__src_00 != (char *)0x0) goto LAB_004322d8;
                  }
                  iVar2 = strcmp(__s1,"cmcc_auth_server_type");
                  if (iVar2 == 0) {
                    __src_00 = (char *)*param_3;
                    __dest = acStack_6dc;
                    if (__src_00 != (char *)0x0) {
                      __n = 100;
                      goto LAB_004322dc;
                    }
                  }
                  iVar2 = strcmp(__s1,"interface");
                  if (iVar2 == 0) {
                    __src_00 = (char *)*param_3;
                    __dest = acStack_6fc;
                    if (__src_00 != (char *)0x0) {
                      __n = 0x20;
                      goto LAB_004322dc;
                    }
                  }
                  iVar2 = strcmp(__s1,"cloud_portal_url");
                  if (iVar2 == 0) {
                    __src_00 = (char *)*param_3;
                    __dest = acStack_5a4;
                    if (__src_00 != (char *)0x0) {
                      __n = 0x7f;
                      goto LAB_004322dc;
                    }
                  }
                  iVar2 = strcmp(__s1,"portal_page_switch");
                  if (iVar2 == 0) {
                    __src_00 = (char *)*param_3;
                    __dest = local_704;
                    if (__src_00 != (char *)0x0) {
                      __n = 4;
                      goto LAB_004322dc;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    iVar9 = iVar9 + 1;
    param_3 = param_3 + 1;
    param_4 = param_4 + 1;
  } while( true );
}

