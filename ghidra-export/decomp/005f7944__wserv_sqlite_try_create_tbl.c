// func _wserv_sqlite_try_create_tbl @ 005f7944 size=1160

undefined4 _wserv_sqlite_try_create_tbl(void)

{
  FILE *pFVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  int local_28 [3];
  
  local_28[0] = 0;
  pFVar1 = fopen("/etc/nouci_config/dbs/wserv.db","a+");
  if (pFVar1 == (FILE *)0x0) {
    if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005f79f8;
    __format = "<wserv>[error]%s(): %d  -> create db file[%s] fail.\r\n";
    uVar3 = 0x216;
    pcVar4 = "/etc/nouci_config/dbs/wserv.db";
  }
  else {
    fclose(pFVar1);
    pFVar1 = fopen("/etc/nouci_config/dbs/wserv_rd.db","a+");
    if (pFVar1 == (FILE *)0x0) {
      if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005f79f8;
      __format = "<wserv>[error]%s(): %d  -> create db file[%s] fail.\r\n";
      uVar3 = 0x221;
      pcVar4 = "/etc/nouci_config/dbs/wserv_rd.db";
    }
    else {
      fclose(pFVar1);
      pFVar1 = fopen("/etc/nouci_config/dbs/wserv_ip.db","a+");
      if (pFVar1 == (FILE *)0x0) {
        if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005f79f8;
        __format = "<wserv>[error]%s(): %d  -> create db file[%s] fail.\r\n";
        uVar3 = 0x22c;
        pcVar4 = "/etc/nouci_config/dbs/wserv_ip.db";
      }
      else {
        fclose(pFVar1);
        iVar2 = _wserv_sqlite_open("/etc/nouci_config/dbs/wserv.db",local_28);
        if (iVar2 == 0) {
          iVar2 = FUN_00407d60(local_28[0],
                               "CREATE TABLE IF NOT EXISTS wserv_tbl (serv_id INTEGER,enable VARCHAR(4),auto_bind VARCHAR(4),default_bind_freq INTEGER,default_bind_vlan INTEGER,ssid VARCHAR(128),ssid_code_type INTEGER,desc VARCHAR(128),isolate INTEGER,ssidbrd INTEGER,encryption INTEGER,auth INTEGER,cipher INTEGER,radius_ip VARCHAR(40),radius_port INTEGER,radius_acct_port INTEGER,radius_pwd VARCHAR(128),key_update_intv INTEGER,key VARCHAR(128),bw_ctrl_enable INTEGER,bw_ctrl_mode INTEGER,up_limit INTEGER,down_limit INTEGER,igmp_snooping_enable VARCHAR(4),igmp_drop_unknown INTEGER,igmp_2g_rate INTEGER,igmp_5g_rate INTEGER,igmp_query_interval INTEGER,igmp_max_resp_time INTEGER,igmp_snooping_switch VARCHAR(4),igmp_query_switch VARCHAR(4),priv_key INTEGER PRIMARY KEY AUTOINCREMENT,ssid_id VARCHAR(65),mlo_switch INTEGER);"
                              );
          if (iVar2 == 0) {
            iVar2 = FUN_00407d60(local_28[0],
                                 "CREATE INDEX IF NOT EXISTS wserv_tbl_serv_id ON wserv_tbl(serv_id);"
                                );
            if (iVar2 == 0) {
              if (local_28[0] != 0) {
                FUN_004080b0();
                local_28[0] = 0;
              }
              iVar2 = _wserv_sqlite_open("/etc/nouci_config/dbs/wserv_rd.db",local_28);
              if (iVar2 == 0) {
                iVar2 = FUN_00407d60(local_28[0],
                                     "CREATE TABLE IF NOT EXISTS bind_tbl (radio_id INTEGER,wserv1 INTEGER,vlan1 INTEGER,wserv2 INTEGER,vlan2 INTEGER,wserv3 INTEGER,vlan3 INTEGER,wserv4 INTEGER,vlan4 INTEGER,wserv5 INTEGER,vlan5 INTEGER,wserv6 INTEGER,vlan6 INTEGER,wserv7 INTEGER,vlan7 INTEGER,wserv8 INTEGER,vlan8 INTEGER,priv_key INTEGER PRIMARY KEY AUTOINCREMENT);"
                                    );
                if (iVar2 == 0) {
                  iVar2 = FUN_00407d60(local_28[0],
                                       "CREATE INDEX IF NOT EXISTS bind_tbl_radio_id ON bind_tbl(radio_id);"
                                      );
                  if (iVar2 == 0) {
                    if (local_28[0] != 0) {
                      FUN_004080b0();
                      local_28[0] = 0;
                    }
                    iVar2 = _wserv_sqlite_open("/etc/nouci_config/dbs/wserv_ip.db",local_28);
                    if (iVar2 == 0) {
                      iVar2 = FUN_00407d60(local_28[0],
                                           "CREATE TABLE IF NOT EXISTS igmp_ip_tbl (id INTEGER,ip_addr VARCHAR(64)UNIQUE,relay INTEGER,enable VARCHAR(4),priv_key INTEGER PRIMARY KEY AUTOINCREMENT);"
                                          );
                      if (iVar2 == 0) {
                        iVar2 = FUN_00407d60(local_28[0],
                                             "CREATE INDEX IF NOT EXISTS igmp_ip_tbl_id ON igmp_ip_tbl(id);"
                                            );
                        if (iVar2 == 0) {
                          uVar5 = 0;
                          goto LAB_005f79fc;
                        }
                        if (g_wserv_error == 0) {
                          uVar5 = 0xffffffff;
                          goto LAB_005f79fc;
                        }
                        iVar2 = is_target_debug_ap();
                        if (iVar2 != 0) {
                          __format = 
                          "<wserv>[error]%s(): %d  -> uac_sqlite_exec_no_cb() fail, sql_cmd=%s\r\n";
                          uVar3 = 0x2ae;
                          pcVar4 = "CREATE INDEX IF NOT EXISTS igmp_ip_tbl_id ON igmp_ip_tbl(id);";
                          goto LAB_005f7b04;
                        }
                      }
                      else if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                        __format = 
                        "<wserv>[error]%s(): %d  -> uac_sqlite_exec_no_cb() fail, sql_cmd=%s\r\n";
                        uVar3 = 0x2a7;
                        pcVar4 = 
                        "CREATE TABLE IF NOT EXISTS igmp_ip_tbl (id INTEGER,ip_addr VARCHAR(64)UNIQUE,relay INTEGER,enable VARCHAR(4),priv_key INTEGER PRIMARY KEY AUTOINCREMENT);"
                        ;
                        goto LAB_005f7b04;
                      }
                    }
                    else if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                      __format = "<wserv>[error]%s(): %d  -> _wserv_sqlite_open() fail, path=%s\r\n"
                      ;
                      uVar3 = 0x29c;
                      pcVar4 = "/etc/nouci_config/dbs/wserv_ip.db";
                      goto LAB_005f7b04;
                    }
LAB_005f79f8:
                    uVar5 = 0xffffffff;
                    goto LAB_005f79fc;
                  }
                  uVar5 = 0xffffffff;
                  if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                  goto LAB_005f79fc;
                  __format = 
                  "<wserv>[error]%s(): %d  -> uac_sqlite_exec_no_cb() fail, sql_cmd=%s\r\n";
                  uVar3 = 0x294;
                  pcVar4 = "CREATE INDEX IF NOT EXISTS bind_tbl_radio_id ON bind_tbl(radio_id);";
                }
                else {
                  if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                  goto LAB_005f79f8;
                  __format = 
                  "<wserv>[error]%s(): %d  -> uac_sqlite_exec_no_cb() fail, sql_cmd=%s\r\n";
                  uVar3 = 0x28d;
                  pcVar4 = 
                  "CREATE TABLE IF NOT EXISTS bind_tbl (radio_id INTEGER,wserv1 INTEGER,vlan1 INTEGER,wserv2 INTEGER,vlan2 INTEGER,wserv3 INTEGER,vlan3 INTEGER,wserv4 INTEGER,vlan4 INTEGER,wserv5 INTEGER,vlan5 INTEGER,wserv6 INTEGER,vlan6 INTEGER,wserv7 INTEGER,vlan7 INTEGER,wserv8 INTEGER,vlan8 INTEGER,priv_key INTEGER PRIMARY KEY AUTOINCREMENT);"
                  ;
                }
              }
              else {
                if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                goto LAB_005f79f8;
                __format = "<wserv>[error]%s(): %d  -> _wserv_sqlite_open() fail, path=%s\r\n";
                uVar3 = 0x274;
                pcVar4 = "/etc/nouci_config/dbs/wserv.db";
              }
            }
            else {
              uVar5 = 0xffffffff;
              if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_005f79fc;
              __format = "<wserv>[error]%s(): %d  -> uac_sqlite_exec_no_cb() fail, sql_cmd=%s\r\n";
              uVar3 = 0x26c;
              pcVar4 = "CREATE INDEX IF NOT EXISTS wserv_tbl_serv_id ON wserv_tbl(serv_id);";
            }
          }
          else {
            if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_005f79f8;
            __format = "<wserv>[error]%s(): %d  -> uac_sqlite_exec_no_cb() fail, sql_cmd=%s\r\n";
            uVar3 = 0x265;
            pcVar4 = 
            "CREATE TABLE IF NOT EXISTS wserv_tbl (serv_id INTEGER,enable VARCHAR(4),auto_bind VARCHAR(4),default_bind_freq INTEGER,default_bind_vlan INTEGER,ssid VARCHAR(128),ssid_code_type INTEGER,desc VARCHAR(128),isolate INTEGER,ssidbrd INTEGER,encryption INTEGER,auth INTEGER,cipher INTEGER,radius_ip VARCHAR(40),radius_port INTEGER,radius_acct_port INTEGER,radius_pwd VARCHAR(128),key_update_intv INTEGER,key VARCHAR(128),bw_ctrl_enable INTEGER,bw_ctrl_mode INTEGER,up_limit INTEGER,down_limit INTEGER,igmp_snooping_enable VARCHAR(4),igmp_drop_unknown INTEGER,igmp_2g_rate INTEGER,igmp_5g_rate INTEGER,igmp_query_interval INTEGER,igmp_max_resp_time INTEGER,igmp_snooping_switch VARCHAR(4),igmp_query_switch VARCHAR(4),priv_key INTEGER PRIMARY KEY AUTOINCREMENT,ssid_id VARCHAR(65),mlo_switch INTEGER);"
            ;
          }
        }
        else {
          if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005f79f8;
          __format = "<wserv>[error]%s(): %d  -> _wserv_sqlite_open() fail, path=%s\r\n";
          uVar3 = 0x237;
          pcVar4 = "/etc/nouci_config/dbs/wserv.db";
        }
      }
    }
  }
LAB_005f7b04:
  uVar5 = 0xffffffff;
  printf(__format,"_wserv_sqlite_try_create_tbl",uVar3,pcVar4);
LAB_005f79fc:
  if (local_28[0] != 0) {
    FUN_004080b0();
  }
  return uVar5;
}

