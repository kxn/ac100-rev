// func rdmngr_db_sqlite_cb @ 0061ae80 size=2924

undefined4 rdmngr_db_sqlite_cb(int param_1,int param_2,undefined4 *param_3,int *param_4)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  void *__dest;
  char *pcVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int *piVar17;
  char *__s1;
  int iVar18;
  int local_358;
  int local_354;
  undefined1 local_350;
  undefined1 local_34f;
  undefined1 local_34e;
  undefined2 local_34c;
  undefined1 local_34a;
  undefined2 local_348;
  undefined2 local_346;
  undefined2 local_342;
  undefined1 local_340;
  undefined1 local_33f;
  undefined2 local_33e;
  undefined1 local_33c;
  undefined2 local_33a;
  undefined2 local_338;
  ushort local_336;
  undefined2 local_334;
  undefined1 local_332;
  undefined1 local_331;
  undefined1 local_330;
  undefined1 local_32f;
  undefined1 local_32e;
  undefined1 local_32d;
  undefined1 local_32c;
  undefined1 local_32b;
  undefined1 local_32a;
  undefined1 local_329;
  undefined1 local_328;
  undefined1 local_327;
  undefined1 local_326;
  undefined1 local_325;
  undefined1 local_324;
  undefined1 local_323;
  undefined1 local_322;
  undefined1 local_321;
  undefined1 local_320;
  undefined1 local_31f;
  undefined1 local_317;
  undefined1 local_316;
  undefined1 local_315;
  undefined1 local_314;
  undefined2 local_312;
  undefined1 local_310;
  undefined1 local_30b;
  undefined1 auStack_300 [728];
  
  memset(&local_358,0,0x54);
  memset(auStack_300,0,0x2d8);
  if ((rdmngr_debug_switch != 0) && (iVar18 = is_target_debug_ap(), iVar18 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d column is %d\n","rdmngr_db_sqlite_cb",0x392,param_2);
  }
  if (param_1 == 0) {
    uVar16 = 0;
    if (rdmngr_err_switch == 0) {
      return 0;
    }
    iVar18 = is_target_debug_ap();
    if (iVar18 == 0) {
      return 0;
    }
    pcVar14 = "[RDMNGR_ERROR]%s()/%d para is null.\n";
    uVar15 = 0x396;
LAB_0061b16c:
    printf(pcVar14,"rdmngr_db_sqlite_cb",uVar15);
    return uVar16;
  }
  bVar1 = false;
  for (iVar18 = 0; iVar9 = local_358, iVar18 < param_2; iVar18 = iVar18 + 1) {
    pcVar14 = (char *)*param_3;
    if ((pcVar14 == (char *)0x0) || (__s1 = (char *)*param_4, __s1 == (char *)0x0)) {
      uVar16 = 1;
      if (rdmngr_err_switch == 0) {
        return 1;
      }
      iVar18 = is_target_debug_ap();
      if (iVar18 == 0) {
        return 1;
      }
      pcVar14 = "[RDMNGR_ERROR]%s()/%d column value or name is null.\n";
      uVar15 = 0x3a0;
      goto LAB_0061b16c;
    }
    iVar9 = strcmp(__s1,"rf_id");
    if (iVar9 == 0) {
      iVar9 = atoi(pcVar14);
      local_358 = iVar9;
      local_354 = atoi(pcVar14);
      iVar11 = apmngr_db_entry_get_by_id((uint)(iVar9 << 0xc) >> 0x10,auStack_300);
      uVar2 = local_326;
      uVar3 = local_325;
      uVar4 = local_324;
      uVar5 = local_323;
      uVar6 = local_322;
      uVar7 = local_320;
      uVar8 = local_31f;
      if (((iVar11 != 0) && (bVar1 = true, rdmngr_err_switch != 0)) &&
         (iVar11 = is_target_debug_ap(), uVar2 = local_326, uVar3 = local_325, uVar4 = local_324,
         uVar5 = local_323, uVar6 = local_322, uVar7 = local_320, uVar8 = local_31f, iVar11 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id failed entry_tmp.radioId:%d.\n",
               "rdmngr_db_sqlite_cb",0x3ab,iVar9);
        uVar2 = local_326;
        uVar3 = local_325;
        uVar4 = local_324;
        uVar5 = local_323;
        uVar6 = local_322;
        uVar7 = local_320;
        uVar8 = local_31f;
      }
    }
    else {
      iVar9 = strcmp(__s1,"rf_name");
      uVar2 = local_326;
      uVar3 = local_325;
      uVar4 = local_324;
      uVar5 = local_323;
      uVar6 = local_322;
      uVar7 = local_320;
      uVar8 = local_31f;
      if (iVar9 != 0) {
        iVar9 = strcmp(__s1,"freq_band");
        if (iVar9 == 0) {
          iVar9 = atoi(pcVar14);
          local_350 = (undefined1)iVar9;
          uVar2 = local_326;
          uVar3 = local_325;
          uVar4 = local_324;
          uVar5 = local_323;
          uVar6 = local_322;
          uVar7 = local_320;
          uVar8 = local_31f;
        }
        else {
          iVar9 = strcmp(__s1,"mode");
          if (iVar9 == 0) {
            iVar9 = atoi(pcVar14);
            local_34f = (undefined1)iVar9;
            uVar2 = local_326;
            uVar3 = local_325;
            uVar4 = local_324;
            uVar5 = local_323;
            uVar6 = local_322;
            uVar7 = local_320;
            uVar8 = local_31f;
          }
          else {
            iVar9 = strcmp(__s1,"bandwidth");
            if (iVar9 == 0) {
              iVar9 = atoi(pcVar14);
              local_34e = (undefined1)iVar9;
              uVar2 = local_326;
              uVar3 = local_325;
              uVar4 = local_324;
              uVar5 = local_323;
              uVar6 = local_322;
              uVar7 = local_320;
              uVar8 = local_31f;
            }
            else {
              iVar9 = strcmp(__s1,"channel");
              if (iVar9 == 0) {
                iVar9 = atoi(pcVar14);
                local_34c = (undefined2)iVar9;
                uVar2 = local_326;
                uVar3 = local_325;
                uVar4 = local_324;
                uVar5 = local_323;
                uVar6 = local_322;
                uVar7 = local_320;
                uVar8 = local_31f;
              }
              else {
                iVar9 = strcmp(__s1,"power_level");
                if (iVar9 == 0) {
                  iVar9 = atoi(pcVar14);
                  local_33f = (undefined1)iVar9;
                  uVar2 = local_326;
                  uVar3 = local_325;
                  uVar4 = local_324;
                  uVar5 = local_323;
                  uVar6 = local_322;
                  uVar7 = local_320;
                  uVar8 = local_31f;
                }
                else {
                  iVar9 = strcmp(__s1,"max_usr");
                  if (iVar9 == 0) {
                    iVar9 = atoi(pcVar14);
                    local_33e = (undefined2)iVar9;
                    uVar2 = local_326;
                    uVar3 = local_325;
                    uVar4 = local_324;
                    uVar5 = local_323;
                    uVar6 = local_322;
                    uVar7 = local_320;
                    uVar8 = local_31f;
                  }
                  else {
                    iVar9 = strcmp(__s1,"antenna");
                    if (iVar9 == 0) {
                      iVar9 = atoi(pcVar14);
                      local_33c = (undefined1)iVar9;
                      uVar2 = local_326;
                      uVar3 = local_325;
                      uVar4 = local_324;
                      uVar5 = local_323;
                      uVar6 = local_322;
                      uVar7 = local_320;
                      uVar8 = local_31f;
                    }
                    else {
                      iVar9 = strcmp(__s1,"frag_thr");
                      if (iVar9 == 0) {
                        iVar9 = atoi(pcVar14);
                        local_33a = (undefined2)iVar9;
                        uVar2 = local_326;
                        uVar3 = local_325;
                        uVar4 = local_324;
                        uVar5 = local_323;
                        uVar6 = local_322;
                        uVar7 = local_320;
                        uVar8 = local_31f;
                      }
                      else {
                        iVar9 = strcmp(__s1,"bcn_intvl");
                        if (iVar9 == 0) {
                          iVar9 = atoi(pcVar14);
                          local_338 = (undefined2)iVar9;
                          uVar2 = local_326;
                          uVar3 = local_325;
                          uVar4 = local_324;
                          uVar5 = local_323;
                          uVar6 = local_322;
                          uVar7 = local_320;
                          uVar8 = local_31f;
                        }
                        else {
                          iVar9 = strcmp(__s1,"manage_frame_rate");
                          if (iVar9 == 0) {
                            iVar9 = atoi(pcVar14);
                            local_32f = (undefined1)iVar9;
                            uVar2 = local_326;
                            uVar3 = local_325;
                            uVar4 = local_324;
                            uVar5 = local_323;
                            uVar6 = local_322;
                            uVar7 = local_320;
                            uVar8 = local_31f;
                          }
                          else {
                            iVar9 = strcmp(__s1,"rts_thr");
                            if (iVar9 == 0) {
                              iVar9 = atoi(pcVar14);
                              local_334 = (undefined2)iVar9;
                              uVar2 = local_326;
                              uVar3 = local_325;
                              uVar4 = local_324;
                              uVar5 = local_323;
                              uVar6 = local_322;
                              uVar7 = local_320;
                              uVar8 = local_31f;
                            }
                            else {
                              iVar9 = strcmp(__s1,"dtim_prd");
                              if (iVar9 == 0) {
                                iVar9 = atoi(pcVar14);
                                local_332 = (undefined1)iVar9;
                                uVar2 = local_326;
                                uVar3 = local_325;
                                uVar4 = local_324;
                                uVar5 = local_323;
                                uVar6 = local_322;
                                uVar7 = local_320;
                                uVar8 = local_31f;
                              }
                              else {
                                iVar9 = strcmp(__s1,"wmm");
                                if (iVar9 == 0) {
                                  iVar9 = strcmp(pcVar14,"on");
                                  local_331 = iVar9 == 0;
                                  uVar2 = local_326;
                                  uVar3 = local_325;
                                  uVar4 = local_324;
                                  uVar5 = local_323;
                                  uVar6 = local_322;
                                  uVar7 = local_320;
                                  uVar8 = local_31f;
                                }
                                else {
                                  iVar9 = strcmp(__s1,"brd_probe");
                                  if (iVar9 == 0) {
                                    iVar9 = strcmp(pcVar14,"on");
                                    local_330 = iVar9 == 0;
                                    uVar2 = local_326;
                                    uVar3 = local_325;
                                    uVar4 = local_324;
                                    uVar5 = local_323;
                                    uVar6 = local_322;
                                    uVar7 = local_320;
                                    uVar8 = local_31f;
                                  }
                                  else {
                                    iVar9 = strcmp(__s1,"short_gi");
                                    if (iVar9 == 0) {
                                      iVar9 = strcmp(pcVar14,"on");
                                      local_32e = iVar9 == 0;
                                      uVar2 = local_326;
                                      uVar3 = local_325;
                                      uVar4 = local_324;
                                      uVar5 = local_323;
                                      uVar6 = local_322;
                                      uVar7 = local_320;
                                      uVar8 = local_31f;
                                    }
                                    else {
                                      iVar9 = strcmp(__s1,"rssi_restrict");
                                      if (iVar9 == 0) {
                                        iVar9 = strcmp(pcVar14,"on");
                                        local_32d = iVar9 == 0;
                                        uVar2 = local_326;
                                        uVar3 = local_325;
                                        uVar4 = local_324;
                                        uVar5 = local_323;
                                        uVar6 = local_322;
                                        uVar7 = local_320;
                                        uVar8 = local_31f;
                                      }
                                      else {
                                        iVar9 = strcmp(__s1,"rssi_restrict_val");
                                        if (iVar9 == 0) {
                                          iVar9 = atoi(pcVar14);
                                          local_32c = (undefined1)iVar9;
                                          uVar2 = local_326;
                                          uVar3 = local_325;
                                          uVar4 = local_324;
                                          uVar5 = local_323;
                                          uVar6 = local_322;
                                          uVar7 = local_320;
                                          uVar8 = local_31f;
                                        }
                                        else {
                                          iVar9 = strcmp(__s1,"rssi_kick");
                                          if (iVar9 == 0) {
                                            if (DAT_007cc660 == 0) {
                                              local_32b = 0;
                                              uVar2 = local_326;
                                              uVar3 = local_325;
                                              uVar4 = local_324;
                                              uVar5 = local_323;
                                              uVar6 = local_322;
                                              uVar7 = local_320;
                                              uVar8 = local_31f;
                                            }
                                            else {
                                              iVar9 = strcmp(pcVar14,"on");
                                              local_32b = iVar9 == 0;
                                              uVar2 = local_326;
                                              uVar3 = local_325;
                                              uVar4 = local_324;
                                              uVar5 = local_323;
                                              uVar6 = local_322;
                                              uVar7 = local_320;
                                              uVar8 = local_31f;
                                            }
                                          }
                                          else {
                                            iVar9 = strcmp(__s1,"rssi_kick_val");
                                            if (iVar9 == 0) {
                                              if (DAT_007cc660 == 0) {
                                                local_32a = 0;
                                                uVar2 = local_326;
                                                uVar3 = local_325;
                                                uVar4 = local_324;
                                                uVar5 = local_323;
                                                uVar6 = local_322;
                                                uVar7 = local_320;
                                                uVar8 = local_31f;
                                              }
                                              else {
                                                iVar9 = atoi(pcVar14);
                                                local_32a = (undefined1)iVar9;
                                                uVar2 = local_326;
                                                uVar3 = local_325;
                                                uVar4 = local_324;
                                                uVar5 = local_323;
                                                uVar6 = local_322;
                                                uVar7 = local_320;
                                                uVar8 = local_31f;
                                              }
                                            }
                                            else {
                                              iVar9 = strcmp(__s1,"chLock");
                                              if (iVar9 == 0) {
                                                iVar9 = atoi(pcVar14);
                                                local_317 = (undefined1)iVar9;
                                                uVar2 = local_326;
                                                uVar3 = local_325;
                                                uVar4 = local_324;
                                                uVar5 = local_323;
                                                uVar6 = local_322;
                                                uVar7 = local_320;
                                                uVar8 = local_31f;
                                              }
                                              else {
                                                iVar9 = strcmp(__s1,"pwrLock");
                                                if (iVar9 == 0) {
                                                  iVar9 = atoi(pcVar14);
                                                  local_316 = (undefined1)iVar9;
                                                  uVar2 = local_326;
                                                  uVar3 = local_325;
                                                  uVar4 = local_324;
                                                  uVar5 = local_323;
                                                  uVar6 = local_322;
                                                  uVar7 = local_320;
                                                  uVar8 = local_31f;
                                                }
                                                else {
                                                  iVar9 = strcmp(__s1,"scanMode");
                                                  if (iVar9 == 0) {
                                                    iVar9 = atoi(pcVar14);
                                                    local_315 = (undefined1)iVar9;
                                                    uVar2 = local_326;
                                                    uVar3 = local_325;
                                                    uVar4 = local_324;
                                                    uVar5 = local_323;
                                                    uVar6 = local_322;
                                                    uVar7 = local_320;
                                                    uVar8 = local_31f;
                                                  }
                                                  else {
                                                    iVar9 = strcmp(__s1,"scanType");
                                                    if (iVar9 == 0) {
                                                      iVar9 = atoi(pcVar14);
                                                      local_314 = (undefined1)iVar9;
                                                      uVar2 = local_326;
                                                      uVar3 = local_325;
                                                      uVar4 = local_324;
                                                      uVar5 = local_323;
                                                      uVar6 = local_322;
                                                      uVar7 = local_320;
                                                      uVar8 = local_31f;
                                                    }
                                                    else {
                                                      iVar9 = strcmp(__s1,"scanIntvl");
                                                      if (iVar9 == 0) {
                                                        iVar9 = atoi(pcVar14);
                                                        local_312 = (undefined2)iVar9;
                                                        uVar2 = local_326;
                                                        uVar3 = local_325;
                                                        uVar4 = local_324;
                                                        uVar5 = local_323;
                                                        uVar6 = local_322;
                                                        uVar7 = local_320;
                                                        uVar8 = local_31f;
                                                      }
                                                      else {
                                                        iVar9 = strcmp(__s1,"rf_state");
                                                        if (iVar9 == 0) {
                                                          iVar9 = strcmp(pcVar14,"on");
                                                          local_310 = iVar9 == 0;
                                                          uVar2 = local_326;
                                                          uVar3 = local_325;
                                                          uVar4 = local_324;
                                                          uVar5 = local_323;
                                                          uVar6 = local_322;
                                                          uVar7 = local_320;
                                                          uVar8 = local_31f;
                                                        }
                                                        else {
                                                          iVar9 = strcmp(__s1,"airtime");
                                                          if (iVar9 == 0) {
                                                            iVar9 = strcmp(pcVar14,"on");
                                                            local_336 = (ushort)(iVar9 == 0);
                                                            uVar2 = local_326;
                                                            uVar3 = local_325;
                                                            uVar4 = local_324;
                                                            uVar5 = local_323;
                                                            uVar6 = local_322;
                                                            uVar7 = local_320;
                                                            uVar8 = local_31f;
                                                          }
                                                          else {
                                                            iVar9 = strcmp(__s1,"rf_chnl_dcs");
                                                            if (iVar9 == 0) {
                                                              iVar9 = atoi(pcVar14);
                                                              local_34a = (undefined1)iVar9;
                                                              uVar2 = local_326;
                                                              uVar3 = local_325;
                                                              uVar4 = local_324;
                                                              uVar5 = local_323;
                                                              uVar6 = local_322;
                                                              uVar7 = local_320;
                                                              uVar8 = local_31f;
                                                            }
                                                            else {
                                                              iVar9 = strcmp(__s1,"rf_chnl_reselect"
                                                                            );
                                                              uVar2 = local_326;
                                                              uVar3 = local_325;
                                                              uVar4 = local_324;
                                                              uVar5 = local_323;
                                                              uVar6 = local_322;
                                                              uVar7 = local_320;
                                                              uVar8 = local_31f;
                                                              if (iVar9 != 0) {
                                                                iVar9 = strcmp(__s1,
                                                  "rf_online_switch");
                                                  if (iVar9 == 0) {
                                                    iVar9 = strcmp(pcVar14,"on");
                                                    local_340 = iVar9 == 0;
                                                    uVar2 = local_326;
                                                    uVar3 = local_325;
                                                    uVar4 = local_324;
                                                    uVar5 = local_323;
                                                    uVar6 = local_322;
                                                    uVar7 = local_320;
                                                    uVar8 = local_31f;
                                                  }
                                                  else {
                                                    iVar9 = strcmp(__s1,"rf_check_circle");
                                                    if (iVar9 == 0) {
                                                      iVar9 = atoi(pcVar14);
                                                      local_348 = (undefined2)iVar9;
                                                      uVar2 = local_326;
                                                      uVar3 = local_325;
                                                      uVar4 = local_324;
                                                      uVar5 = local_323;
                                                      uVar6 = local_322;
                                                      uVar7 = local_320;
                                                      uVar8 = local_31f;
                                                    }
                                                    else {
                                                      iVar9 = strcmp(__s1,"rf_chnl_occup_threshold")
                                                      ;
                                                      if (iVar9 == 0) {
                                                        iVar9 = atoi(pcVar14);
                                                        local_346 = (undefined2)iVar9;
                                                        uVar2 = local_326;
                                                        uVar3 = local_325;
                                                        uVar4 = local_324;
                                                        uVar5 = local_323;
                                                        uVar6 = local_322;
                                                        uVar7 = local_320;
                                                        uVar8 = local_31f;
                                                      }
                                                      else {
                                                        iVar9 = strcmp(__s1,"rf_chnl_tolerance");
                                                        if (iVar9 == 0) {
                                                          iVar9 = atoi(pcVar14);
                                                          local_342 = (undefined2)iVar9;
                                                          uVar2 = local_326;
                                                          uVar3 = local_325;
                                                          uVar4 = local_324;
                                                          uVar5 = local_323;
                                                          uVar6 = local_322;
                                                          uVar7 = local_320;
                                                          uVar8 = local_31f;
                                                        }
                                                        else {
                                                          iVar9 = strcmp(__s1,"chErrFrameRatio");
                                                          uVar2 = local_326;
                                                          uVar3 = local_325;
                                                          uVar4 = local_324;
                                                          uVar5 = local_323;
                                                          uVar6 = local_322;
                                                          uVar7 = local_320;
                                                          uVar8 = local_31f;
                                                          if (iVar9 != 0) {
                                                            iVar9 = strcmp(__s1,"reject_limit");
                                                            if (iVar9 == 0) {
                                                              iVar9 = atoi(pcVar14);
                                                              local_329 = (undefined1)iVar9;
                                                              uVar2 = local_326;
                                                              uVar3 = local_325;
                                                              uVar4 = local_324;
                                                              uVar5 = local_323;
                                                              uVar6 = local_322;
                                                              uVar7 = local_320;
                                                              uVar8 = local_31f;
                                                            }
                                                            else {
                                                              iVar9 = strcmp(__s1,"reject_enable");
                                                              if (iVar9 == 0) {
                                                                iVar9 = strcmp(pcVar14,"on");
                                                                local_328 = iVar9 == 0;
                                                                uVar2 = local_326;
                                                                uVar3 = local_325;
                                                                uVar4 = local_324;
                                                                uVar5 = local_323;
                                                                uVar6 = local_322;
                                                                uVar7 = local_320;
                                                                uVar8 = local_31f;
                                                              }
                                                              else {
                                                                iVar9 = strcmp(__s1,"reject_diff");
                                                                if (iVar9 == 0) {
                                                                  iVar9 = atoi(pcVar14);
                                                                  local_327 = (undefined1)iVar9;
                                                                  uVar2 = local_326;
                                                                  uVar3 = local_325;
                                                                  uVar4 = local_324;
                                                                  uVar5 = local_323;
                                                                  uVar6 = local_322;
                                                                  uVar7 = local_320;
                                                                  uVar8 = local_31f;
                                                                }
                                                                else {
                                                                  iVar9 = strcmp(__s1,
                                                  "downlink_mumimo");
                                                  if (iVar9 == 0) {
                                                    iVar9 = strcmp(pcVar14,"null");
                                                    uVar2 = 0xff;
                                                    uVar3 = local_325;
                                                    uVar4 = local_324;
                                                    uVar5 = local_323;
                                                    uVar6 = local_322;
                                                    uVar7 = local_320;
                                                    uVar8 = local_31f;
                                                    if (iVar9 != 0) {
                                                      iVar9 = strcmp(pcVar14,"on");
                                                      uVar2 = iVar9 == 0;
                                                      uVar3 = local_325;
                                                      uVar4 = local_324;
                                                      uVar5 = local_323;
                                                      uVar6 = local_322;
                                                      uVar7 = local_320;
                                                      uVar8 = local_31f;
                                                    }
                                                  }
                                                  else {
                                                    iVar9 = strcmp(__s1,"uplink_mumimo");
                                                    if (iVar9 == 0) {
                                                      iVar9 = strcmp(pcVar14,"null");
                                                      uVar2 = local_326;
                                                      uVar3 = 0xff;
                                                      uVar4 = local_324;
                                                      uVar5 = local_323;
                                                      uVar6 = local_322;
                                                      uVar7 = local_320;
                                                      uVar8 = local_31f;
                                                      if (iVar9 != 0) {
                                                        iVar9 = strcmp(pcVar14,"on");
                                                        uVar2 = local_326;
                                                        uVar3 = iVar9 == 0;
                                                        uVar4 = local_324;
                                                        uVar5 = local_323;
                                                        uVar6 = local_322;
                                                        uVar7 = local_320;
                                                        uVar8 = local_31f;
                                                      }
                                                    }
                                                    else {
                                                      iVar9 = strcmp(__s1,"downlink_ofdma");
                                                      if (iVar9 == 0) {
                                                        iVar9 = strcmp(pcVar14,"null");
                                                        uVar2 = local_326;
                                                        uVar3 = local_325;
                                                        uVar4 = 0xff;
                                                        uVar5 = local_323;
                                                        uVar6 = local_322;
                                                        uVar7 = local_320;
                                                        uVar8 = local_31f;
                                                        if (iVar9 != 0) {
                                                          iVar9 = strcmp(pcVar14,"on");
                                                          uVar2 = local_326;
                                                          uVar3 = local_325;
                                                          uVar4 = iVar9 == 0;
                                                          uVar5 = local_323;
                                                          uVar6 = local_322;
                                                          uVar7 = local_320;
                                                          uVar8 = local_31f;
                                                        }
                                                      }
                                                      else {
                                                        iVar9 = strcmp(__s1,"uplink_ofdma");
                                                        if (iVar9 == 0) {
                                                          iVar9 = strcmp(pcVar14,"null");
                                                          uVar2 = local_326;
                                                          uVar3 = local_325;
                                                          uVar4 = local_324;
                                                          uVar5 = 0xff;
                                                          uVar6 = local_322;
                                                          uVar7 = local_320;
                                                          uVar8 = local_31f;
                                                          if (iVar9 != 0) {
                                                            iVar9 = strcmp(pcVar14,"on");
                                                            uVar2 = local_326;
                                                            uVar3 = local_325;
                                                            uVar4 = local_324;
                                                            uVar5 = iVar9 == 0;
                                                            uVar6 = local_322;
                                                            uVar7 = local_320;
                                                            uVar8 = local_31f;
                                                          }
                                                        }
                                                        else {
                                                          iVar9 = strcmp(__s1,"twt");
                                                          if (iVar9 == 0) {
                                                            iVar9 = strcmp(pcVar14,"null");
                                                            uVar2 = local_326;
                                                            uVar3 = local_325;
                                                            uVar4 = local_324;
                                                            uVar5 = local_323;
                                                            uVar6 = 0xff;
                                                            uVar7 = local_320;
                                                            uVar8 = local_31f;
                                                            if (iVar9 != 0) {
                                                              iVar9 = strcmp(pcVar14,"on");
                                                              uVar2 = local_326;
                                                              uVar3 = local_325;
                                                              uVar4 = local_324;
                                                              uVar5 = local_323;
                                                              uVar6 = iVar9 == 0;
                                                              uVar7 = local_320;
                                                              uVar8 = local_31f;
                                                            }
                                                          }
                                                          else {
                                                            iVar9 = strcmp(__s1,"gi_mode");
                                                            if (iVar9 == 0) {
                                                              iVar9 = atoi(pcVar14);
                                                              local_321 = (undefined1)iVar9;
                                                              uVar2 = local_326;
                                                              uVar3 = local_325;
                                                              uVar4 = local_324;
                                                              uVar5 = local_323;
                                                              uVar6 = local_322;
                                                              uVar7 = local_320;
                                                              uVar8 = local_31f;
                                                            }
                                                            else {
                                                              iVar9 = strcmp(__s1,"enable_6g");
                                                              if (iVar9 == 0) {
                                                                iVar9 = strcmp(pcVar14,"null");
                                                                uVar2 = local_326;
                                                                uVar3 = local_325;
                                                                uVar4 = local_324;
                                                                uVar5 = local_323;
                                                                uVar6 = local_322;
                                                                uVar7 = 0xff;
                                                                uVar8 = local_31f;
                                                                if (iVar9 != 0) {
                                                                  iVar9 = strcmp(pcVar14,"on");
                                                                  uVar2 = local_326;
                                                                  uVar3 = local_325;
                                                                  uVar4 = local_324;
                                                                  uVar5 = local_323;
                                                                  uVar6 = local_322;
                                                                  uVar7 = iVar9 == 0;
                                                                  uVar8 = local_31f;
                                                                }
                                                              }
                                                              else {
                                                                iVar9 = strcmp(__s1,"enable_6g_psc")
                                                                ;
                                                                if (iVar9 == 0) {
                                                                  iVar9 = strcmp(pcVar14,"null");
                                                                  uVar2 = local_326;
                                                                  uVar3 = local_325;
                                                                  uVar4 = local_324;
                                                                  uVar5 = local_323;
                                                                  uVar6 = local_322;
                                                                  uVar7 = local_320;
                                                                  uVar8 = 0xff;
                                                                  if (iVar9 != 0) {
                                                                    iVar9 = strcmp(pcVar14,"on");
                                                                    uVar2 = local_326;
                                                                    uVar3 = local_325;
                                                                    uVar4 = local_324;
                                                                    uVar5 = local_323;
                                                                    uVar6 = local_322;
                                                                    uVar7 = local_320;
                                                                    uVar8 = iVar9 == 0;
                                                                  }
                                                                }
                                                                else {
                                                                  iVar9 = strcmp(__s1,"key");
                                                                  uVar2 = local_326;
                                                                  uVar3 = local_325;
                                                                  uVar4 = local_324;
                                                                  uVar5 = local_323;
                                                                  uVar6 = local_322;
                                                                  uVar7 = local_320;
                                                                  uVar8 = local_31f;
                                                                  if (iVar9 != 0) {
                                                                    if (rdmngr_err_switch == 0) {
                                                                      return 1;
                                                                    }
                                                                    iVar18 = is_target_debug_ap();
                                                                    if (iVar18 == 0) {
                                                                      return 1;
                                                                    }
                                                                    iVar9 = *param_4;
                                                                    pcVar14 = 
                                                  "[RDMNGR_ERROR]%s()/%d Invalid column_name[%s]\n";
                                                  uVar16 = 0x476;
                                                  goto LAB_0061b23c;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    local_31f = uVar8;
    local_320 = uVar7;
    local_322 = uVar6;
    local_323 = uVar5;
    local_324 = uVar4;
    local_325 = uVar3;
    local_326 = uVar2;
    param_4 = param_4 + 1;
    param_3 = param_3 + 1;
  }
  if (bVar1) {
    FUN_00407ec0(local_358,g_invalid_radioId,&g_invalid_radioId_pos);
    return 0;
  }
  uVar10 = rdmngr_db_generate_rd_idx_by_rd_id();
  iVar18 = DAT_007cc65c;
  if (-1 < (int)uVar10) {
    iVar11 = apmngr_db_get_ap_max();
    iVar12 = apmngr_db_get_template_max();
    iVar13 = apmngr_db_get_sensor_max();
    if (uVar10 < (uint)((iVar11 + iVar12 + iVar13) * iVar18)) {
      local_30b = 1;
      piVar17 = (int *)(param_1 + uVar10 * 8);
      if (*piVar17 != 0) {
        __dest = (void *)piVar17[1];
LAB_0061b298:
        memcpy(__dest,&local_358,0x54);
        return 0;
      }
      if (piVar17[1] != 0) {
        __dest = (void *)piVar17[1];
        goto LAB_0061b298;
      }
      iVar18 = FUN_004082a0(1,0x54,0x48b);
      piVar17[1] = iVar18;
      if (iVar18 != 0) {
        __dest = (void *)piVar17[1];
        goto LAB_0061b298;
      }
      if (rdmngr_err_switch == 0) {
        return 1;
      }
      iVar18 = is_target_debug_ap();
      if (iVar18 == 0) {
        return 1;
      }
      pcVar14 = "[RDMNGR_ERROR]%s()/%d Malloc entry for radio Id %d failed.\n";
      uVar16 = 0x48e;
      goto LAB_0061b23c;
    }
  }
  if (rdmngr_err_switch == 0) {
    return 1;
  }
  iVar18 = is_target_debug_ap();
  if (iVar18 == 0) {
    return 1;
  }
  pcVar14 = "[RDMNGR_ERROR]%s()/%d Invalid radio Id : 0x%x in column_value.\n";
  uVar16 = 0x484;
LAB_0061b23c:
  printf(pcVar14,"rdmngr_db_sqlite_cb",uVar16,iVar9);
  return 1;
}

