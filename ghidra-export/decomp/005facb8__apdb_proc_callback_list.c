// func _apdb_proc_callback_list @ 005facb8 size=1644

undefined4
_apdb_proc_callback_list
          (int param_1,uint param_2,undefined4 *param_3,uint param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *__format;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  code *pcVar10;
  
  if ((param_3 == (undefined4 *)0x0) && (apdb_debug_switch != 0)) {
    printf("[APDB_DEBUG]%s()/line %d : new_ap_item is NULL\n","_apdb_proc_callback_list",0x12b8);
  }
  iVar1 = FUN_004081b0(&l_apdb_callback_list);
  if (iVar1 == 0) {
    return 0;
  }
  pcVar10 = *(code **)(iVar1 + 0x10);
  do {
    if ((pcVar10 == (code *)0x0) ||
       (iVar2 = (*pcVar10)(param_3,param_4,param_1,param_2), iVar2 != -1)) {
      pcVar10 = *(code **)(iVar1 + 0x14);
    }
    else if (apdb_debug_switch == 0) {
      pcVar10 = *(code **)(iVar1 + 0x14);
    }
    else {
      printf("[APDB_DEBUG]%s()/line %d : process callback update_all for module[%s] failed.\n",
             "_apdb_proc_callback_list",0x12c2,*(undefined4 *)(iVar1 + 0xc));
      pcVar10 = *(code **)(iVar1 + 0x14);
    }
    if (pcVar10 != (code *)0x0) {
      if (param_3 == (undefined4 *)0x0) {
        if (apdb_err_switch != 0) {
          printf("[APDB_ERROR]%s()/line %d : input new array error.\n","_apdb_check_ap_update",
                 0x123c);
        }
LAB_005faf80:
        if (apdb_debug_switch != 0) {
          printf("[APDB_DEBUG]%s()/line %d : check ap update failed.\n","_apdb_proc_callback_list",
                 0x12cc);
          return 0xffffffff;
        }
        return 0xffffffff;
      }
      if (param_1 != 0) {
        uVar8 = 0;
        uVar9 = 0;
LAB_005fad6c:
        if (uVar9 < param_4) {
          if (uVar8 < param_2) {
            piVar6 = param_3 + uVar9 * 0x16;
            piVar7 = (int *)(param_1 + uVar8 * 0x58);
            if (piVar6 == (int *)0x0) {
              if (apdb_err_switch != 0) {
                __format = "[APDB_ERROR]%s()/line %d : input new array error\n";
                uVar4 = 0x11fc;
LAB_005fafe0:
                printf(__format,"_apdb_compare_ap",uVar4);
              }
LAB_005faf70:
              if (apdb_err_switch != 0) {
                printf("[APDB_ERROR]%s()/line %d : error update type for AP[0x%x] in new array and AP[0x%x] in old array,please check.\n"
                       ,"_apdb_check_ap_update",0x1283,*piVar6,*piVar7);
              }
              goto LAB_005faf80;
            }
            if (piVar7 == (int *)0x0) {
              if (apdb_err_switch != 0) {
                __format = "[APDB_ERROR]%s()/line %d : input old array error\n";
                uVar4 = 0x1201;
                goto LAB_005fafe0;
              }
              goto LAB_005faf70;
            }
            if (*piVar6 == *piVar7) {
              iVar2 = piVar6[0x13];
LAB_005fae50:
              if (iVar2 != piVar7[0x13]) {
                *param_5 = 1;
                if (apdb_debug_switch == 0) {
                  iVar2 = piVar6[0x13];
                }
                else {
                  printf("[APDB_DEBUG]%s()/line %d : ap[id:0x%x,name:%s] has been updated.\n",
                         "_apdb_check_ap_update",0x1276,*piVar6,piVar6 + 2);
                  iVar2 = piVar6[0x13];
                }
                (*pcVar10)(piVar6[0x15] + (iVar2 + -1) * 0x168,
                           piVar7[0x15] + (piVar7[0x13] + -1) * 0x168,2);
              }
              uVar9 = uVar9 + 1;
              uVar8 = uVar8 + 1;
            }
            else {
              if (apdb_debug_switch == 0) {
                iVar2 = *piVar6;
              }
              else {
                printf("[APDB_DEBUG]%s()/line %d : new id:0x%x,old id:0x%x\n","_apdb_compare_ap",
                       0x1208,*piVar6,*piVar7);
                iVar2 = *piVar6;
              }
              iVar5 = *piVar7;
              if (iVar5 < iVar2) {
                if (apdb_debug_switch != 0) {
                  printf("[APDB_DEBUG]%s()/line %d : old ap[id:0x%x,name:%s] has been deleted.\n",
                         "_apdb_compare_ap",0x120c,iVar5,piVar7 + 2);
                }
                *param_5 = 1;
                if (apdb_debug_switch == 0) {
                  iVar2 = piVar7[0x13];
                }
                else {
                  puVar3 = (undefined4 *)(param_1 + uVar9 * 0x58);
                  printf("[APDB_DEBUG]%s()/line %d : ap[id:0x%x,name:%s] has been deleted.\n",
                         "_apdb_check_ap_update",0x126b,*puVar3,puVar3 + 2);
                  iVar2 = piVar7[0x13];
                }
                uVar8 = uVar8 + 1;
                (*pcVar10)(0,piVar7[0x15] + (iVar2 + -1) * 0x168,1);
              }
              else {
                if (iVar5 <= iVar2) {
                  iVar2 = piVar6[0x13];
                  goto LAB_005fae50;
                }
                if (apdb_debug_switch != 0) {
                  printf("[APDB_DEBUG]%s()/line %d : new ap[id:0x%x,name:%s] is new added.\n",
                         "_apdb_compare_ap",0x1211,iVar2,piVar6 + 2);
                }
                *param_5 = 1;
                if (apdb_debug_switch == 0) {
                  iVar2 = piVar6[0x13];
                }
                else {
                  printf("[APDB_DEBUG]%s()/line %d : ap[id:0x%x,name:%s] has been added.\n",
                         "_apdb_check_ap_update",0x1260,*piVar6,piVar6 + 2);
                  iVar2 = piVar6[0x13];
                }
                uVar9 = uVar9 + 1;
                (*pcVar10)(piVar6[0x15] + (iVar2 + -1) * 0x168,0,0);
              }
            }
            goto LAB_005fad6c;
          }
          *param_5 = 1;
          puVar3 = param_3 + uVar9 * 0x16;
          for (; uVar9 != param_4; uVar9 = uVar9 + 1) {
            if (apdb_debug_switch == 0) {
              uVar4 = puVar3[0x15];
            }
            else {
              printf("[APDB_DEBUG]%s()/line %d : new ap[id:0x%x,name:%s] has been added.\n",
                     "_apdb_check_ap_update",0x128f,*puVar3,puVar3 + 2);
              uVar4 = puVar3[0x15];
            }
            puVar3 = puVar3 + 0x16;
            (*pcVar10)(uVar4,0,0);
          }
        }
        if (uVar8 < param_2) {
          *param_5 = 1;
          puVar3 = (undefined4 *)(param_1 + uVar8 * 0x58);
          for (; uVar8 != param_2; uVar8 = uVar8 + 1) {
            if (apdb_debug_switch == 0) {
              iVar2 = puVar3[0x13];
            }
            else {
              printf("[APDB_DEBUG]%s()/line %d : old ap[id:0x%x,name:%s] has been deleted.\n",
                     "_apdb_check_ap_update",0x129d,*puVar3,puVar3 + 2);
              iVar2 = puVar3[0x13];
            }
            piVar6 = puVar3 + 0x15;
            puVar3 = puVar3 + 0x16;
            (*pcVar10)(0,*piVar6 + (iVar2 + -1) * 0x168,1);
          }
        }
        goto LAB_005fae30;
      }
      *param_5 = 1;
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : all entry in new array is new added.\n",
               "_apdb_check_ap_update",0x1244);
      }
      if (param_4 != 0) {
        uVar8 = 0;
        puVar3 = param_3;
        while (uVar8 != param_4) {
          if (puVar3[0x15] != 0) {
            (*pcVar10)(puVar3[0x15],0,0);
          }
          if (apdb_debug_switch == 0) {
            uVar8 = uVar8 + 1;
            puVar3 = puVar3 + 0x16;
          }
          else {
            printf("[APDB_DEBUG]%s()/line %d : process ap[0x%x]\n","_apdb_check_ap_update",0x124d,
                   *puVar3);
            uVar8 = uVar8 + 1;
            puVar3 = puVar3 + 0x16;
          }
        }
      }
    }
LAB_005fae30:
    iVar1 = FUN_00408680(iVar1);
    if (iVar1 == 0) {
      return 0;
    }
    pcVar10 = *(code **)(iVar1 + 0x10);
  } while( true );
}

