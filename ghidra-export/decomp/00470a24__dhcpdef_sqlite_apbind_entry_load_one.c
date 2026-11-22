// func _dhcpdef_sqlite_apbind_entry_load_one @ 00470a24 size=1612

undefined4
_dhcpdef_sqlite_apbind_entry_load_one
          (undefined4 param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  void *__s;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  uint local_3d0 [2];
  undefined4 local_3c8;
  undefined1 local_3c4 [4];
  uint local_3c0;
  undefined1 auStack_3bc [172];
  undefined1 auStack_310 [728];
  int local_38;
  undefined4 *local_34;
  int local_30;
  
  local_3d0[0] = 0;
  local_3d0[1] = 0;
  local_3c8 = 0;
  local_3c4 = (undefined1  [4])0x0;
  local_3c0 = (uint)local_3c0._1_3_;
  memset(auStack_310,0,0x2d8);
  uVar4 = dhcpdef_db_get_max_svr_per_ap();
  __s = (void *)FUN_004082a0(uVar4,4,0x13e);
  if (__s == (void *)0x0) {
    uVar4 = 1;
    if ((g_dhcpdef_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
             "_dhcpdef_sqlite_apbind_entry_load_one",0x141);
    }
  }
  else {
    local_3c4 = (undefined1  [4])((uint)__s >> 8);
    local_3c0._0_1_ = SUB41(__s,0);
    uVar11 = 0;
    local_3d0[0] = 0xffffffff;
    local_3c8 = 0;
    iVar5 = dhcpdef_db_get_max_svr_per_ap();
    memset(__s,0,iVar5 << 2);
    while( true ) {
      uVar6 = dhcpdef_db_get_max_svr_per_ap();
      uVar1 = (uint)(local_3c4 + 1) & 3;
      if (uVar6 <= uVar11) break;
      iVar5 = uVar11 * 4;
      uVar11 = uVar11 + 1;
      *(undefined4 *)
       (iVar5 + (*(int *)(local_3c4 + 1 + -uVar1) << uVar1 * 8 & 0xffffff00U | local_3c0 >> 0x18)) =
           0xffffffff;
    }
    bVar2 = false;
    uVar4 = 1;
    for (local_38 = 0; local_38 < param_2; local_38 = local_38 + 1) {
      pcVar12 = (char *)*param_4;
      if ((pcVar12 == (char *)0x0) || (pcVar13 = (char *)*param_3, pcVar13 == (char *)0x0)) {
        if ((g_dhcpdef_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("\x1b[31;49m[%s]<%s():%d> column_name or column_value is null!\x1b[0m\r\n",
                 "dhcp_defend","_dhcpdef_sqlite_apbind_entry_load_one",0x14c);
        }
LAB_00470bd8:
        if (bVar2) goto LAB_00470fe4;
        goto LAB_00470be0;
      }
      iVar5 = strcmp(pcVar12,"ap_id");
      if (iVar5 == 0) {
        local_3d0[0] = atoi(pcVar13);
        iVar5 = apmngr_db_entry_get_by_id(local_3d0[0] & 0xffff,auStack_310);
        if (iVar5 != 0) {
          if ((g_dhcpdef_error == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) {
LAB_00470c4c:
            bVar2 = true;
            uVar4 = 0;
          }
          else {
            pcVar12 = "\x1b[31;49m[%s]<%s():%d> apmngr_db_entry_get_by_id(%d) fail.\x1b[0m\r\n";
            uVar4 = 0x156;
            uVar11 = local_3d0[0];
LAB_00470e00:
            bVar2 = true;
            printf(pcVar12,"dhcp_defend","_dhcpdef_sqlite_apbind_entry_load_one",uVar4,uVar11);
            uVar4 = 0;
          }
        }
      }
      else {
        iVar5 = strcmp(pcVar12,"enable");
        if (iVar5 == 0) {
          iVar5 = atoi(pcVar13);
          local_3c8 = CONCAT13((char)iVar5,local_3c8._1_3_);
        }
        else {
          iVar5 = strcmp(pcVar12,"svr_ids");
          if (iVar5 == 0) {
            memset(auStack_3bc,0,0xac);
            if ((g_dhcpdef_info != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend",
                     "_dhcpdef_sqlite_apbind_entry_load_svr_ids",0xe6,
                     "_dhcpdef_sqlite_apbind_entry_load_svr_ids");
            }
            iVar5 = dhcpdef_db_get_max_svr_per_ap();
            pcVar12 = (char *)FUN_00408450(iVar5 * 6 + 1,0xe8);
            if (pcVar12 == (char *)0x0) {
              if ((g_dhcpdef_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
                       "_dhcpdef_sqlite_apbind_entry_load_svr_ids",0xeb);
              }
            }
            else {
              pcVar13 = (char *)*param_3;
              iVar5 = dhcpdef_db_get_max_svr_per_ap();
              strncpy(pcVar12,pcVar13,iVar5 * 6);
              iVar5 = dhcpdef_db_get_max_svr_per_ap();
              pcVar12[iVar5 * 6] = '\0';
              uVar7 = dhcpdef_db_get_max_svr_per_ap();
              puVar8 = (undefined4 *)FUN_004082a0(uVar7,4,0xf3);
              if (puVar8 == (undefined4 *)0x0) {
                if ((g_dhcpdef_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                  printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
                         "_dhcpdef_sqlite_apbind_entry_load_svr_ids",0xf6);
                }
                bVar3 = true;
                if (pcVar12 == (char *)0x0) goto LAB_00470d88;
              }
              else {
                uVar7 = dhcpdef_db_get_max_svr_per_ap();
                local_30 = dhcpdef_util_str_split(pcVar12,&DAT_00678b90,puVar8,uVar7);
                if (((local_30 < 1) && (g_dhcpdef_warn != 0)) &&
                   (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                  printf("\x1b[33;49m[%s]<%s():%d> ap_id[%d] does NOT bind any servers!\x1b[0m\r\n",
                         "dhcp_defend","_dhcpdef_sqlite_apbind_entry_load_svr_ids",0xfe,local_3d0[0]
                        );
                }
                local_34 = puVar8;
                for (iVar5 = 0; iVar5 < local_30; iVar5 = iVar5 + 1) {
                  iVar9 = atoi((char *)*local_34);
                  iVar10 = dhcpdef_db_svr_entry_get(iVar9,auStack_3bc);
                  local_34 = local_34 + 1;
                  if (iVar10 != 0) {
                    bVar3 = true;
                    if ((g_dhcpdef_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                      printf("\x1b[31;49m[%s]<%s():%d> dhcpdef_db_svr_entry_get failed!\x1b[0m\r\n",
                             "dhcp_defend","_dhcpdef_sqlite_apbind_entry_load_svr_ids",0x106);
                    }
                    goto LAB_00470d6c;
                  }
                  *(int *)(iVar5 * 4 + CONCAT31(local_3c4._1_3_,local_3c0._0_1_)) = iVar9;
                }
                local_3c8._1_3_ = (undefined3)((uint)iVar5 >> 8);
                local_3c4[0] = (undefined1)iVar5;
                bVar3 = false;
LAB_00470d6c:
                FUN_00407df0(puVar8);
              }
              FUN_00407df0(pcVar12);
              if (!bVar3) goto LAB_00470b2c;
            }
LAB_00470d88:
            bVar2 = true;
            if (g_dhcpdef_error == 0) goto LAB_00470c4c;
            iVar5 = is_target_debug_ap();
            if (iVar5 != 0) {
              pcVar12 = 
              "\x1b[31;49m[%s]<%s():%d> _dhcpdef_sqlite_apbind_entry_load_svr_ids(%s) fail.\x1b[0m\r\n"
              ;
              uVar4 = 0x163;
              uVar11 = *param_3;
              goto LAB_00470e00;
            }
            uVar4 = 0;
          }
          else {
            iVar5 = strcmp(pcVar12,"priv_key");
            if (iVar5 != 0) {
              if ((g_dhcpdef_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                printf("\x1b[31;49m[%s]<%s():%d> invalid column_name[%s]!\x1b[0m\r\n","dhcp_defend",
                       "_dhcpdef_sqlite_apbind_entry_load_one",0x16a,*param_4);
              }
              goto LAB_00470bd8;
            }
          }
        }
      }
LAB_00470b2c:
      param_4 = param_4 + 1;
      param_3 = param_3 + 1;
    }
    if (bVar2) {
LAB_00470fe4:
      FUN_00407ec0(local_3d0[0],g_invalid_ap_id,&g_invalid_ap_id_pos);
    }
    else {
      iVar5 = dhcpdef_db_apbind_entry_load(local_3d0);
      if (iVar5 == 0) {
        uVar4 = 0;
      }
    }
LAB_00470be0:
    FUN_00407df0(__s);
  }
  return uVar4;
}

