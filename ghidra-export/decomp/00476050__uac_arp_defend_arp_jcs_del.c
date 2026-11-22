// func _uac_arp_defend_arp_jcs_del @ 00476050 size=2160

void _uac_arp_defend_arp_jcs_del(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char *__dest;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  FILE *__s;
  size_t sVar8;
  undefined4 *puVar9;
  char *pcVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  int local_3c;
  undefined4 *local_38;
  int local_34;
  
  iVar1 = FUN_004082a0(1000,4,0x4ed);
  if (iVar1 == 0) {
    if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d no memory!\n","_uac_arp_defend_arp_jcs_del",0x4f0);
    }
    __dest = (char *)0x0;
LAB_0047628c:
    puVar4 = (undefined4 *)0x0;
    puVar5 = (undefined4 *)0x0;
  }
  else {
    __dest = (char *)FUN_00408450(0x1771,0x4f4);
    if (__dest == (char *)0x0) {
      if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[ARP_DEFEND_ERROR]%s()/%d no memory!\n","_uac_arp_defend_arp_jcs_del",0x4f7);
      }
      goto LAB_0047628c;
    }
    iVar2 = json_object_object_get(param_1,"arp_id");
    if (iVar2 == 0) {
      puVar5 = (undefined4 *)0x0;
      if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[ARP_DEFEND_ERROR]%s()/%d %s not found!\n","_uac_arp_defend_arp_jcs_del",0x4fc,
               "arp_id");
        puVar4 = (undefined4 *)0x0;
        goto LAB_00476294;
      }
      goto LAB_0047628c;
    }
    memset(__dest,0,0x1771);
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 6) {
      pcVar10 = (char *)json_object_get_string(iVar2);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_arp_defend_arp_jcs_del",0x4ff);
      }
      pcVar10 = "";
    }
    strncpy(__dest,pcVar10,6000);
    __dest[6000] = '\0';
    iVar2 = FUN_00474a6c(__dest,iVar1,1000);
    if (iVar2 < 1) {
      if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[ARP_DEFEND_ERROR]%s()/%d _uac_arp_defend_util_str_split() fail, str: %s!\n",
               "_uac_arp_defend_arp_jcs_del",0x504,__dest);
      }
      goto LAB_0047628c;
    }
    if ((arp_defend_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[ARP_DEFEND_DEBUG]%s()/%d _uac_arp_defend_arp_jcs_del() begin, ids=%s.\n",
             "_uac_arp_defend_arp_jcs_del",0x508,__dest);
    }
    puVar4 = (undefined4 *)FUN_004082a0(iVar2,4,0x50a);
    if (puVar4 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
      if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[ARP_DEFEND_ERROR]%s()/%d no memory.\n","_uac_arp_defend_arp_jcs_del",0x50d);
      }
    }
    else {
      puVar5 = (undefined4 *)FUN_004082a0(iVar2,4,0x510);
      if (puVar5 != (undefined4 *)0x0) {
        iVar3 = 0;
        iVar12 = 0;
        do {
          iVar12 = iVar12 + 1;
          iVar6 = atoi(*(char **)(iVar1 + iVar3));
          *(int *)((int)puVar4 + iVar3) = iVar6;
          puVar7 = (undefined4 *)((int)puVar5 + iVar3);
          iVar3 = iVar3 + 4;
          *puVar7 = 0;
        } while (iVar12 != iVar2);
        iVar3 = arp_defend_db_apbind_entry_count();
        if (iVar3 < 1) {
          if ((arp_defend_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[ARP_DEFEND_DEBUG]%s()/%d no ap on the system, just return!\n",
                   "_uac_arp_defend_arp_jcs_del",0x51f);
          }
          puVar7 = (undefined4 *)0x0;
          iVar12 = 0;
LAB_00476474:
          local_34 = 0;
          local_3c = 0;
          puVar9 = puVar4;
          puVar14 = puVar5;
          do {
            iVar3 = arp_defend_db_arp_entry_del(*puVar9);
            if (iVar3 == 0) {
              *puVar14 = 1;
              local_3c = local_3c + 1;
            }
            else if ((arp_defend_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[ARP_DEFEND_ERROR]%s()/%d arp_defend_db_arp_entry_del(%d) failed.\n",
                     "_uac_arp_defend_arp_jcs_del",0x548,*puVar9);
            }
            puVar9 = puVar9 + 1;
            puVar14 = puVar14 + 1;
            local_34 = local_34 + 1;
          } while (local_34 != iVar2);
          iVar6 = 0;
          iVar3 = json_object_new_array();
          local_38 = puVar5;
          if (iVar3 != 0) {
            do {
              iVar6 = iVar6 + 1;
              uVar13 = json_object_new_int(*local_38);
              json_object_array_add(iVar3,uVar13);
              local_38 = local_38 + 1;
            } while (iVar6 != iVar2);
            __s = fopen("/tmp/arp_defend_arp_del","w+");
            if (__s == (FILE *)0x0) {
              uVar13 = 0xffffffff;
              if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[ARP_DEFEND_ERROR]%s()/%d open file[%s] fail!\n",
                       "_uac_arp_defend_arp_jcs_del",0x560,"/tmp/arp_defend_arp_del");
              }
            }
            else {
              pcVar10 = (char *)json_object_to_json_string_ext(iVar3,0);
              if (pcVar10 == (char *)0x0) {
                uVar13 = 0xffffffff;
                if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  pcVar10 = "[ARP_DEFEND_ERROR]%s()/%d JSON_STRING_FROM_OBJ() fail!\n";
                  uVar11 = 0x567;
LAB_00476800:
                  uVar13 = 0xffffffff;
                  printf(pcVar10,"_uac_arp_defend_arp_jcs_del",uVar11);
                }
              }
              else {
                if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[ARP_DEFEND_DEBUG]%s()/%d out_arr: %s\n","_uac_arp_defend_arp_jcs_del",
                         0x56a,pcVar10);
                }
                sVar8 = strlen(pcVar10);
                sVar8 = fwrite(pcVar10,sVar8,1,__s);
                if (sVar8 == 1) {
                  uVar13 = 0;
                  uVar11 = json_object_new_string("/tmp/arp_defend_arp_del");
                  json_object_object_add(param_2,"file_name",uVar11);
                  uVar11 = json_object_new_int(local_3c);
                  json_object_object_add(param_2,"succ_num",uVar11);
                }
                else {
                  uVar13 = 0xffffffff;
                  if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                    pcVar10 = "[ARP_DEFEND_ERROR]%s()/%d write result to file fail!\n";
                    uVar11 = 0x56f;
                    goto LAB_00476800;
                  }
                }
              }
            }
            json_object_put(iVar3);
            if (__s != (FILE *)0x0) {
              fclose(__s);
            }
            goto LAB_004761dc;
          }
          uVar13 = 0xffffffff;
          if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_004761dc;
          pcVar10 = "[ARP_DEFEND_ERROR]%s()/%d JSON_ARRAY_CREATE() fail!\n";
          uVar11 = 0x554;
LAB_0047676c:
          uVar13 = 0xffffffff;
          printf(pcVar10,"_uac_arp_defend_arp_jcs_del",uVar11);
        }
        else {
          iVar12 = FUN_004082a0(iVar3,4,0x522);
          if (iVar12 == 0) {
            if (arp_defend_err_switch != 0) {
              iVar2 = is_target_debug_ap();
              puVar7 = (undefined4 *)0x0;
              if (iVar2 == 0) {
                uVar13 = 0xffffffff;
                goto LAB_004761dc;
              }
              pcVar10 = "[ARP_DEFEND_ERROR]%s()/%d no memory!\n";
              uVar11 = 0x525;
              goto LAB_0047676c;
            }
          }
          else {
            iVar6 = arp_defend_db_apbind_entry_get_all_ids(iVar12,iVar3);
            if (iVar6 == 0) {
              puVar7 = (undefined4 *)FUN_004082a0(iVar3,4,0x52e);
              if (puVar7 != (undefined4 *)0x0) {
                iVar6 = 0;
                puVar9 = puVar7;
                do {
                  iVar6 = iVar6 + 1;
                  *puVar9 = 0;
                  puVar9 = puVar9 + 1;
                } while (iVar6 != iVar3);
                iVar3 = arp_defend_db_batch_unbind(iVar12,iVar6,puVar4,iVar2,puVar7);
                if (iVar3 != 0) {
                  uVar13 = 0xffffffff;
                  goto LAB_004761dc;
                }
                iVar3 = FUN_00474804(iVar12,iVar6,puVar7);
                if (iVar3 != 0) {
                  uVar13 = 0xffffffff;
                  goto LAB_004761dc;
                }
                goto LAB_00476474;
              }
              uVar13 = 0xffffffff;
              if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_004761dc;
              pcVar10 = "[ARP_DEFEND_ERROR]%s()/%d no memory.\n";
              uVar11 = 0x531;
              goto LAB_0047676c;
            }
          }
          puVar7 = (undefined4 *)0x0;
          uVar13 = 0xffffffff;
        }
        goto LAB_004761dc;
      }
      if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[ARP_DEFEND_ERROR]%s()/%d no memory.\n","_uac_arp_defend_arp_jcs_del",0x513);
      }
    }
  }
LAB_00476294:
  puVar7 = (undefined4 *)0x0;
  iVar12 = 0;
  uVar13 = 0xffffffff;
LAB_004761dc:
  if (iVar12 != 0) {
    FUN_00407df0(iVar12);
  }
  if (puVar7 != (undefined4 *)0x0) {
    FUN_00407df0(puVar7);
  }
  if (puVar4 != (undefined4 *)0x0) {
    FUN_00407df0(puVar4);
  }
  if (iVar1 != 0) {
    FUN_00407df0(iVar1);
  }
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
  if (puVar5 != (undefined4 *)0x0) {
    FUN_00407df0(puVar5);
  }
  if ((arp_defend_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[ARP_DEFEND_DEBUG]%s()/%d _uac_arp_defend_arp_jcs_del() finish, ret=%d.\n",
           "_uac_arp_defend_arp_jcs_del",0x5aa,uVar13);
    return;
  }
  return;
}

