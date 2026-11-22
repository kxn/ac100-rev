// func main @ 0040a2c0 size=3396

void main(void)

{
  uint uVar1;
  int iVar2;
  char *__format;
  int local_18 [3];
  
  local_18[0] = -1;
  uVar1 = 1;
  if (init_trace == 0) {
    iVar2 = access("/tmp/uac_init_trace_open",0);
    uVar1 = (uint)(iVar2 == 0);
  }
  init_trace = uVar1;
  udbg_dup_stdout("/dev/console");
  FUN_00407fd0(1,1,0xe);
  FUN_00408650();
  FUN_004085a0();
  FUN_0051e578();
  FUN_00408110();
  FUN_00408510();
  udbg_init();
  if (init_trace != 0) {
    puts(" -- Run > uac_cfg_init(5)");
  }
  iVar2 = FUN_00407e00(5);
  if (iVar2 == 0) {
    if (init_trace != 0) {
      puts(" -- Run > uac_profile_get_int(\"wheel_timer\", \"id_len\", &timer_bit)");
    }
    iVar2 = FUN_0051eb48("wheel_timer","id_len",local_18);
    if (iVar2 == 0) {
      if (init_trace != 0) {
        puts(" -- Run > uac_timer_init(timer_bit)");
      }
      iVar2 = FUN_00407d90(local_18[0]);
      if (iVar2 == 0) {
        if (init_trace != 0) {
          puts(" -- Run > uac_md5_timer_init(timer_bit-5)");
        }
        iVar2 = FUN_00407f10(local_18[0] + -5);
        if (iVar2 == 0) {
          if (init_trace != 0) {
            puts(" -- Run > cw_ac_init()");
          }
          iVar2 = cw_ac_init();
          if (iVar2 == 0) {
            if (init_trace != 0) {
              puts(" -- Run > apdb_init()");
            }
            iVar2 = apdb_init();
            if (iVar2 == 0) {
              if (init_trace != 0) {
                puts(" -- Run > systime_init()");
              }
              iVar2 = systime_init();
              if (iVar2 == 0) {
                if (init_trace != 0) {
                  puts(" -- Run > apmngr_init()");
                }
                iVar2 = apmngr_init();
                if (iVar2 == 0) {
                  if (init_trace != 0) {
                    puts(" -- Run > multi_link_init()");
                  }
                  iVar2 = multi_link_init();
                  if (iVar2 == 0) {
                    if (init_trace != 0) {
                      puts(" -- Run > apmngr_multilink_callback_init()");
                    }
                    iVar2 = apmngr_multilink_callback_init();
                    if (iVar2 == 0) {
                      if (init_trace != 0) {
                        puts(" -- Run > apmngr_db_sqlite_recover()");
                      }
                      iVar2 = apmngr_db_sqlite_recover();
                      if (iVar2 == 0) {
                        if (init_trace != 0) {
                          puts(" -- Run > uac_rdmngr_init()");
                        }
                        iVar2 = uac_rdmngr_init();
                        if (iVar2 == 0) {
                          if (init_trace != 0) {
                            puts(" -- Run > rate_info_init()");
                          }
                          iVar2 = rate_info_init();
                          if (iVar2 == 0) {
                            if (init_trace != 0) {
                              puts(" -- Run > band_navigation_init()");
                            }
                            iVar2 = band_navigation_init();
                            if (iVar2 == 0) {
                              if (init_trace != 0) {
                                puts(" -- Run > uac_wservice_init()");
                              }
                              iVar2 = uac_wservice_init();
                              if (iVar2 == 0) {
                                if (init_trace != 0) {
                                  puts(" -- Run > uac_wstation_init()");
                                }
                                iVar2 = uac_wstation_init();
                                if (iVar2 == 0) {
                                  if (init_trace != 0) {
                                    puts(" -- Run > uac_stats_init()");
                                  }
                                  iVar2 = uac_stats_init();
                                  if (iVar2 == 0) {
                                    if (init_trace != 0) {
                                      puts(" -- Run > apupd_init()");
                                    }
                                    iVar2 = apupd_init();
                                    if (iVar2 == 0) {
                                      if (init_trace != 0) {
                                        puts(" -- Run > acpdt_init()");
                                      }
                                      iVar2 = acpdt_init();
                                      if (iVar2 == 0) {
                                        if (init_trace != 0) {
                                          puts(" -- Run > ac_passthrough_init()");
                                        }
                                        iVar2 = ac_passthrough_init();
                                        if (iVar2 == 0) {
                                          if (init_trace != 0) {
                                            puts(" -- Run > wportal_init()");
                                          }
                                          iVar2 = wportal_init();
                                          if (iVar2 == 0) {
                                            if (init_trace != 0) {
                                              puts(" -- Run > radius_init()");
                                            }
                                            iVar2 = FUN_00408030();
                                            if (iVar2 == 0) {
                                              if (init_trace != 0) {
                                                puts(" -- Run > audit_client_init()");
                                              }
                                              iVar2 = audit_client_init();
                                              if (iVar2 == 0) {
                                                if (init_trace != 0) {
                                                  puts(" -- Run > uac_mac_auth_init()");
                                                }
                                                iVar2 = uac_mac_auth_init();
                                                if (iVar2 == 0) {
                                                  if (init_trace != 0) {
                                                    puts(" -- Run > uac_bcast_storm_ctrl_init()");
                                                  }
                                                  iVar2 = uac_bcast_storm_ctrl_init();
                                                  if (iVar2 == 0) {
                                                    if (init_trace != 0) {
                                                      puts(" -- Run > uac_dhcpdef_init()");
                                                    }
                                                    iVar2 = uac_dhcpdef_init();
                                                    if (iVar2 == 0) {
                                                      if (init_trace != 0) {
                                                        puts(" -- Run > uac_arp_defend_init()");
                                                      }
                                                      iVar2 = uac_arp_defend_init();
                                                      if (iVar2 == 0) {
                                                        if (init_trace != 0) {
                                                          puts(" -- Run > wsta_roam_init()");
                                                        }
                                                        iVar2 = wsta_roam_init();
                                                        if (iVar2 == 0) {
                                                          if (init_trace != 0) {
                                                            puts(" -- Run > balance_init()");
                                                          }
                                                          iVar2 = balance_init();
                                                          if (iVar2 == 0) {
                                                            if (init_trace != 0) {
                                                              puts(" -- Run > uac_rrm_init()");
                                                            }
                                                            iVar2 = uac_rrm_init();
                                                            if (iVar2 == 0) {
                                                              system(
                                                  "ubus call cloudclient register_cmd_callback \'{\"register_notify_cmd\":\"echo 9\",\"wait_time\":0,\"type\":\"feature\",\"action\":\"add\"}\' &> /dev/null"
                                                  );
                                                  if (init_trace != 0) {
                                                    puts(" -- Run > uac_report_init()");
                                                  }
                                                  iVar2 = uac_report_init();
                                                  if (iVar2 == 0) {
                                                    if (init_trace != 0) {
                                                      puts(" -- Run > cloud_mngt_init()");
                                                    }
                                                    iVar2 = cloud_mngt_init();
                                                    if (iVar2 == 0) {
                                                      if (init_trace != 0) {
                                                        puts(" -- Run > uac_mesh_init()");
                                                      }
                                                      iVar2 = uac_mesh_init();
                                                      if (iVar2 == 0) {
                                                        if (init_trace != 0) {
                                                          puts(" -- Run > uac_sensor_init()");
                                                        }
                                                        iVar2 = uac_sensor_init();
                                                        if (iVar2 == 0) {
                                                          if (init_trace != 0) {
                                                            puts(" -- Run > ucl_auth_init()");
                                                          }
                                                          iVar2 = FUN_00408200();
                                                          if (iVar2 == 0) {
                                                            if (init_trace != 0) {
                                                              puts(" -- Run > uac_lldp_init()");
                                                            }
                                                            iVar2 = uac_lldp_init();
                                                            if (iVar2 == 0) {
                                                              if (init_trace != 0) {
                                                                puts(" -- Run > uac_id_sync_init()")
                                                                ;
                                                              }
                                                              iVar2 = uac_id_sync_init();
                                                              if (iVar2 == 0) {
                                                                FUN_00408640();
                                                                FUN_00408010();
                                                                if (init_trace != 0) {
                                                                  puts(" -- Run > cw_ac_run()");
                                                                }
                                                                iVar2 = cw_ac_run();
                                                                if (iVar2 == 0) {
                                                                  uac_done();
                                                                  system(
                                                  "ubus call cloudclient check_report_message_status \'{\"callback\":\"lua /usr/lib/lua/luci/model/apmngr_cloud_report_switch.lua \"}\' &> /dev/null"
                                                  );
                                                  do {
                                                    sleep(1);
                                                  } while( true );
                                                  }
                                                  if (init_trace == 0) goto LAB_0040a364;
                                                  __format = "Init error: cw_ac_run() return %d\n";
                                                  }
                                                  else {
                                                    if (init_trace == 0) goto LAB_0040a364;
                                                    __format = 
                                                  "Init error: uac_id_sync_init() return %d\n";
                                                  }
                                                  }
                                                  else {
                                                    if (init_trace == 0) goto LAB_0040a364;
                                                    __format = 
                                                  "Init error: uac_lldp_init() return %d\n";
                                                  }
                                                  }
                                                  else {
                                                    if (init_trace == 0) goto LAB_0040a364;
                                                    __format = 
                                                  "Init error: ucl_auth_init() return %d\n";
                                                  }
                                                  }
                                                  else {
                                                    if (init_trace == 0) goto LAB_0040a364;
                                                    __format = 
                                                  "Init error: uac_sensor_init() return %d\n";
                                                  }
                                                  }
                                                  else {
                                                    if (init_trace == 0) goto LAB_0040a364;
                                                    __format = 
                                                  "Init error: uac_mesh_init() return %d\n";
                                                  }
                                                  }
                                                  else {
                                                    if (init_trace == 0) goto LAB_0040a364;
                                                    __format = 
                                                  "Init error: cloud_mngt_init() return %d\n";
                                                  }
                                                  }
                                                  else {
                                                    if (init_trace == 0) goto LAB_0040a364;
                                                    __format = 
                                                  "Init error: uac_report_init() return %d\n";
                                                  }
                                                  }
                                                  else {
                                                    if (init_trace == 0) goto LAB_0040a364;
                                                    __format = 
                                                  "Init error: uac_rrm_init() return %d\n";
                                                  }
                                                  }
                                                  else {
                                                    if (init_trace == 0) goto LAB_0040a364;
                                                    __format = 
                                                  "Init error: balance_init() return %d\n";
                                                  }
                                                  }
                                                  else {
                                                    if (init_trace == 0) goto LAB_0040a364;
                                                    __format = 
                                                  "Init error: wsta_roam_init() return %d\n";
                                                  }
                                                  }
                                                  else {
                                                    if (init_trace == 0) goto LAB_0040a364;
                                                    __format = 
                                                  "Init error: uac_arp_defend_init() return %d\n";
                                                  }
                                                  }
                                                  else {
                                                    if (init_trace == 0) goto LAB_0040a364;
                                                    __format = 
                                                  "Init error: uac_dhcpdef_init() return %d\n";
                                                  }
                                                  }
                                                  else {
                                                    if (init_trace == 0) goto LAB_0040a364;
                                                    __format = 
                                                  "Init error: uac_bcast_storm_ctrl_init() return %d\n"
                                                  ;
                                                  }
                                                }
                                                else {
                                                  if (init_trace == 0) goto LAB_0040a364;
                                                  __format = 
                                                  "Init error: uac_mac_auth_init() return %d\n";
                                                }
                                              }
                                              else {
                                                if (init_trace == 0) goto LAB_0040a364;
                                                __format = 
                                                "Init error: audit_client_init() return %d\n";
                                              }
                                            }
                                            else {
                                              if (init_trace == 0) goto LAB_0040a364;
                                              __format = "Init error: radius_init() return %d\n";
                                            }
                                          }
                                          else {
                                            if (init_trace == 0) goto LAB_0040a364;
                                            __format = "Init error: wportal_init() return %d\n";
                                          }
                                        }
                                        else {
                                          if (init_trace == 0) goto LAB_0040a364;
                                          __format = "Init error: ac_passthrough_init() return %d\n"
                                          ;
                                        }
                                      }
                                      else {
                                        if (init_trace == 0) goto LAB_0040a364;
                                        __format = "Init error: acpdt_init() return %d\n";
                                      }
                                    }
                                    else {
                                      if (init_trace == 0) goto LAB_0040a364;
                                      __format = "Init error: apupd_init() return %d\n";
                                    }
                                  }
                                  else {
                                    if (init_trace == 0) goto LAB_0040a364;
                                    __format = "Init error: uac_stats_init() return %d\n";
                                  }
                                }
                                else {
                                  if (init_trace == 0) goto LAB_0040a364;
                                  __format = "Init error: uac_wstation_init() return %d\n";
                                }
                              }
                              else {
                                if (init_trace == 0) goto LAB_0040a364;
                                __format = "Init error: uac_wservice_init() return %d\n";
                              }
                            }
                            else {
                              if (init_trace == 0) goto LAB_0040a364;
                              __format = "Init error: band_navigation_init() return %d\n";
                            }
                          }
                          else {
                            if (init_trace == 0) goto LAB_0040a364;
                            __format = "Init error: rate_info_init() return %d\n";
                          }
                        }
                        else {
                          if (init_trace == 0) goto LAB_0040a364;
                          __format = "Init error: uac_rdmngr_init() return %d\n";
                        }
                      }
                      else {
                        if (init_trace == 0) goto LAB_0040a364;
                        __format = "Init error: apmngr_db_sqlite_recover() return %d\n";
                      }
                    }
                    else {
                      if (init_trace == 0) goto LAB_0040a364;
                      __format = "Init error: apmngr_multilink_callback_init() return %d\n";
                    }
                  }
                  else {
                    if (init_trace == 0) goto LAB_0040a364;
                    __format = "Init error: multi_link_init() return %d\n";
                  }
                }
                else {
                  if (init_trace == 0) goto LAB_0040a364;
                  __format = "Init error: apmngr_init() return %d\n";
                }
              }
              else {
                if (init_trace == 0) goto LAB_0040a364;
                __format = "Init error: systime_init() return %d\n";
              }
            }
            else {
              if (init_trace == 0) goto LAB_0040a364;
              __format = "Init error: apdb_init() return %d\n";
            }
          }
          else {
            if (init_trace == 0) goto LAB_0040a364;
            __format = "Init error: cw_ac_init() return %d\n";
          }
        }
        else {
          if (init_trace == 0) goto LAB_0040a364;
          __format = "Init error: uac_md5_timer_init(timer_bit-5) return %d\n";
        }
      }
      else {
        if (init_trace == 0) goto LAB_0040a364;
        __format = "Init error: uac_timer_init(timer_bit) return %d\n";
      }
    }
    else {
      if (init_trace == 0) goto LAB_0040a364;
      __format = 
      "Init error: uac_profile_get_int(\"wheel_timer\", \"id_len\", &timer_bit) return %d\n";
    }
  }
  else {
    if (init_trace == 0) goto LAB_0040a364;
    __format = "Init error: uac_cfg_init(5) return %d\n";
  }
  printf(__format,iVar2);
LAB_0040a364:
  if (init_trace != 0) {
    puts(" -- Destroy > apdb_destroy()");
  }
  apdb_destroy();
  if (init_trace != 0) {
    puts(" -- Destroy > band_navigation_destroy()");
  }
  band_navigation_destroy();
  if (init_trace != 0) {
    puts(" -- Destroy > rate_info_destroy()");
  }
  rate_info_destroy();
  if (init_trace != 0) {
    puts(" -- Destroy > uac_wstation_uninit()");
  }
  uac_wstation_uninit();
  if (init_trace != 0) {
    puts(" -- Destroy > uac_wservice_uninit()");
  }
  uac_wservice_uninit();
  if (init_trace != 0) {
    puts(" -- Destroy > multi_link_fini()");
  }
  multi_link_fini();
  if (init_trace != 0) {
    puts(" -- Destroy > apmngr_fini()");
  }
  apmngr_fini();
  if (init_trace != 0) {
    puts(" -- Destroy > cw_ac_destroy()");
  }
  cw_ac_destroy();
  if (init_trace != 0) {
    puts(" -- Destroy > audit_client_destroy()");
  }
  audit_client_destroy();
  if (init_trace != 0) {
    puts(" -- Destroy > ucl_auth_fini()");
  }
  FUN_004086e0();
  if (init_trace != 0) {
    puts(" -- Destroy > wportal_destroy()");
  }
  wportal_destroy();
  if (init_trace != 0) {
    puts(" -- Destroy > uac_rdmngr_uninit()");
  }
  uac_rdmngr_uninit();
  if (init_trace != 0) {
    puts(" -- Destroy > uac_mac_auth_uninit()");
  }
  uac_mac_auth_uninit();
  if (init_trace != 0) {
    puts(" -- Destroy > uac_bcast_storm_ctrl_destroy()");
  }
  uac_bcast_storm_ctrl_destroy();
  if (init_trace != 0) {
    puts(" -- Destroy > uac_dhcpdef_uninit()");
  }
  uac_dhcpdef_uninit();
  if (init_trace != 0) {
    puts(" -- Destroy > uac_arp_defend_uninit()");
  }
  uac_arp_defend_uninit();
  if (init_trace != 0) {
    puts(" -- Destroy > wsta_roam_uninit()");
  }
  wsta_roam_uninit();
  if (init_trace != 0) {
    puts(" -- Destroy > cloud_mngt_fini()");
  }
  cloud_mngt_fini();
  if (init_trace != 0) {
    puts(" -- Destroy > uac_lldp_fini()");
  }
  uac_lldp_fini();
  if (init_trace != 0) {
    puts(" -- Destroy > ac_passthrough_fini()");
  }
  ac_passthrough_fini();
  if (init_trace != 0) {
    puts(" -- Destroy > uac_rrm_uninit()");
  }
  uac_rrm_uninit();
  if (init_trace != 0) {
    puts(" -- Destroy > uac_report_uninit()");
  }
  uac_report_uninit();
  if (init_trace != 0) {
    puts(" -- Destroy > uac_mesh_uninit()");
  }
  uac_mesh_uninit();
  if (init_trace != 0) {
    puts(" -- Destroy > uac_sensor_uninit()");
  }
  uac_sensor_uninit();
  if (init_trace != 0) {
    puts(" -- Destroy > uac_id_sync_uninit()");
  }
  uac_id_sync_uninit();
  puts("Warning: Init uac process failed, exit...");
                    /* WARNING: Subroutine does not return */
  exit(0);
}

