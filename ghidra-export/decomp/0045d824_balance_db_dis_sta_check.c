// func balance_db_dis_sta_check @ 0045d824 size=1928

undefined4 balance_db_dis_sta_check(byte *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  uint *puVar14;
  int iVar15;
  uint extraout_v1;
  char *__format;
  undefined4 uVar16;
  uint uVar17;
  
  if ((((param_1 == (byte *)0x0) || (param_2 == 0)) || (balance_wtp_hash == 0)) ||
     ((balance_dis_sta_hash == 0 || (balance_com == (uint *)0x0)))) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[BALANCE_ERROR](%32s) %05d: inputs error.\r\n","balance_db_dis_sta_check",0x686);
    return 0xffffffff;
  }
  FUN_004082d0(balance_db_mutex,0xffffffff);
  if (balance_com[2] == 0) {
    if ((g_balance_warning == 0) || (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 == 0))
    goto LAB_0045d8b4;
    uVar2 = (uint)*(byte *)(param_2 + 9);
    uVar17 = (uint)*(byte *)(param_2 + 8);
    __format = 
    "[BALANCE_WARNING](%32s) %05d: balance is off, so wtp(%02x:%02x:%02x:%02x:%02x:%02x) accepts station(%02x:%02x:%02x:%02x:%02x:%02x).\r\n"
    ;
    uVar3 = (uint)*(byte *)(param_2 + 10);
    uVar16 = 0x691;
    uVar4 = (uint)*(byte *)(param_2 + 0xb);
    uVar5 = (uint)*(byte *)(param_2 + 0xc);
    uVar6 = (uint)*(byte *)(param_2 + 0xd);
    uVar7 = (uint)*param_1;
    uVar8 = (uint)param_1[1];
    uVar9 = (uint)param_1[2];
    uVar10 = (uint)param_1[3];
    uVar11 = (uint)param_1[4];
    uVar12 = (uint)param_1[5];
  }
  else {
    pbVar13 = (byte *)FUN_00407fa0(balance_dis_sta_hash,param_1);
    if (pbVar13 == (byte *)0x0) {
      if ((g_balance_warning == 0) || (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 == 0))
      goto LAB_0045d8b4;
      uVar2 = (uint)param_1[1];
      uVar17 = (uint)*param_1;
      __format = 
      "[BALANCE_WARNING](%32s) %05d: get discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) failed, so wtp(%02x:%02x:%02x:%02x:%02x:%02x) accepts it.\r\n"
      ;
      uVar3 = (uint)param_1[2];
      uVar16 = 0x69a;
      uVar4 = (uint)param_1[3];
      uVar5 = (uint)param_1[4];
      uVar6 = (uint)param_1[5];
      uVar7 = (uint)*(byte *)(param_2 + 8);
      uVar8 = (uint)*(byte *)(param_2 + 9);
      uVar9 = (uint)*(byte *)(param_2 + 10);
      uVar10 = (uint)*(byte *)(param_2 + 0xb);
      uVar11 = (uint)*(byte *)(param_2 + 0xc);
      uVar12 = (uint)*(byte *)(param_2 + 0xd);
    }
    else {
      FUN_00407e70();
      if ((((extraout_v1 < *(uint *)(pbVar13 + 0xc)) ||
           (0x3b < extraout_v1 - *(uint *)(pbVar13 + 0xc))) &&
          (pbVar13[8] = 0, pbVar13[9] = 0, pbVar13[10] = 0, pbVar13[0xb] = 0, g_balance_warning != 0
          )) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[BALANCE_WARNING](%32s) %05d: discovery-station clear fail number\r\n",
               "balance_db_dis_sta_check",0x6a5);
      }
      if (balance_com[6] < *(int *)(pbVar13 + 8) + 1U) {
        if ((g_balance_warning == 0) || (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 == 0))
        goto LAB_0045d8b4;
        __format = 
        "[BALANCE_WARNING](%32s) %05d: over the max fail number(%d), so wtp(%02x:%02x:%02x:%02x:%02x:%02x) accepts station(%02x:%02x:%02x:%02x:%02x:%02x)\r\n"
        ;
        uVar17 = balance_com[6];
        uVar16 = 0x6ab;
        uVar2 = (uint)*(byte *)(param_2 + 8);
        uVar3 = (uint)*(byte *)(param_2 + 9);
        uVar4 = (uint)*(byte *)(param_2 + 10);
        uVar5 = (uint)*(byte *)(param_2 + 0xb);
        uVar6 = (uint)*(byte *)(param_2 + 0xc);
        uVar7 = (uint)*(byte *)(param_2 + 0xd);
        uVar8 = (uint)*pbVar13;
        uVar9 = (uint)pbVar13[1];
        uVar10 = (uint)pbVar13[2];
        uVar11 = (uint)pbVar13[3];
        uVar12 = (uint)pbVar13[4];
      }
      else {
        puVar14 = (uint *)FUN_00407fa0(balance_wtp_hash,param_2 + 8);
        if (puVar14 == (uint *)0x0) {
          if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 != 0))
          {
            printf("[BALANCE_ERROR](%32s) %05d: get wtp(%02x:%02x:%02x:%02x:%02x:%02x) failed, so wtp reject station(%02x:%02x:%02x:%02x:%02x:%02x).\r\n"
                   ,"balance_db_dis_sta_check",0x6b4,(uint)*(byte *)(param_2 + 8),
                   (uint)*(byte *)(param_2 + 9),(uint)*(byte *)(param_2 + 10),
                   (uint)*(byte *)(param_2 + 0xb),(uint)*(byte *)(param_2 + 0xc),
                   (uint)*(byte *)(param_2 + 0xd),(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
                   (uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
          }
LAB_0045de0c:
          FUN_00407f30(balance_db_mutex);
          return 0xffffffff;
        }
        if (balance_com[4] <= puVar14[4]) {
          for (iVar1 = FUN_004081b0(pbVar13 + 0x10); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
            uVar2 = *(uint *)(iVar1 + 0xc);
            if (((*balance_com < uVar2) ||
                (iVar15 = balance_wtp_array + uVar2 * 0x14, *(int *)(iVar15 + 4) == 0)) ||
               (uVar2 == *puVar14)) {
              if ((g_balance_warning != 0) && (iVar15 = is_target_debug_ap(), iVar15 != 0)) {
                printf("[BALANCE_WARNING](%32s) %05d: wtp(%d)\'s state is %d\r\n",
                       "balance_db_dis_sta_check",0x6ce,*puVar14,
                       *(undefined4 *)(balance_wtp_array + *(int *)(iVar1 + 0xc) * 0x14 + 4));
              }
            }
            else {
              uVar2 = *(uint *)(iVar15 + 0x10);
              if ((uVar2 < puVar14[4]) && (balance_com[5] <= puVar14[4] - uVar2)) {
                *(uint *)(pbVar13 + 0xc) = extraout_v1;
                *(int *)(pbVar13 + 8) = *(int *)(pbVar13 + 8) + 1;
                if ((g_balance_warning != 0) &&
                   (iVar15 = is_target_debug_ap(balance_db_mutex), iVar15 != 0)) {
                  iVar1 = balance_wtp_array + *(int *)(iVar1 + 0xc) * 0x14;
                  printf("[BALANCE_WARNING](%32s) %05d: wtp(%02x:%02x:%02x:%02x:%02x:%02x)(%d) and wtp(%02x:%02x:%02x:%02x:%02x:%02x)(%d) reach the differ threshold(%d), wtp rejects station(%02x:%02x:%02x:%02x:%02x:%02x).\r\n"
                         ,"balance_db_dis_sta_check",0x6da,(uint)*(byte *)(puVar14 + 2),
                         (uint)*(byte *)((int)puVar14 + 9),(uint)*(byte *)((int)puVar14 + 10),
                         (uint)*(byte *)((int)puVar14 + 0xb),(uint)*(byte *)(puVar14 + 3),
                         (uint)*(byte *)((int)puVar14 + 0xd),puVar14[4],(uint)*(byte *)(iVar1 + 8),
                         (uint)*(byte *)(iVar1 + 9),(uint)*(byte *)(iVar1 + 10),
                         (uint)*(byte *)(iVar1 + 0xb),(uint)*(byte *)(iVar1 + 0xc),
                         (uint)*(byte *)(iVar1 + 0xd),*(undefined4 *)(iVar1 + 0x10),balance_com[5],
                         (uint)*pbVar13,(uint)pbVar13[1],(uint)pbVar13[2],(uint)pbVar13[3],
                         (uint)pbVar13[4],(uint)pbVar13[5]);
                }
                goto LAB_0045de0c;
              }
            }
          }
          if ((g_balance_warning != 0) && (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 != 0)
             ) {
            printf("[BALANCE_WARNING](%32s) %05d: wtp(%02x:%02x:%02x:%02x:%02x:%02x)(%d) reach threshlod(%d), but in differ-threshold(%d) with other wtps, so wtp accepts station(%02x:%02x:%02x:%02x:%02x:%02x).\r\n"
                   ,"balance_db_dis_sta_check",0x6e2,(uint)*(byte *)(puVar14 + 2),
                   (uint)*(byte *)((int)puVar14 + 9),(uint)*(byte *)((int)puVar14 + 10),
                   (uint)*(byte *)((int)puVar14 + 0xb),(uint)*(byte *)(puVar14 + 3),
                   (uint)*(byte *)((int)puVar14 + 0xd),puVar14[4],balance_com[4],balance_com[5],
                   (uint)*pbVar13,(uint)pbVar13[1],(uint)pbVar13[2],(uint)pbVar13[3],
                   (uint)pbVar13[4],(uint)pbVar13[5]);
          }
          goto LAB_0045d8b4;
        }
        if ((g_balance_warning == 0) || (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 == 0))
        goto LAB_0045d8b4;
        uVar2 = (uint)*(byte *)((int)puVar14 + 9);
        uVar17 = (uint)*(byte *)(puVar14 + 2);
        __format = 
        "[BALANCE_WARNING](%32s) %05d: wtp(%02x:%02x:%02x:%02x:%02x:%02x)\'s stations cann\'t reach threshold(%d), so wtp accepts station(%02x:%02x:%02x:%02x:%02x:%02x).\r\n"
        ;
        uVar3 = (uint)*(byte *)((int)puVar14 + 10);
        uVar16 = 0x6bd;
        uVar4 = (uint)*(byte *)((int)puVar14 + 0xb);
        uVar5 = (uint)*(byte *)(puVar14 + 3);
        uVar6 = (uint)*(byte *)((int)puVar14 + 0xd);
        uVar7 = balance_com[4];
        uVar8 = (uint)*pbVar13;
        uVar9 = (uint)pbVar13[1];
        uVar10 = (uint)pbVar13[2];
        uVar11 = (uint)pbVar13[3];
        uVar12 = (uint)pbVar13[4];
      }
    }
  }
  printf(__format,"balance_db_dis_sta_check",uVar16,uVar17,uVar2,uVar3,uVar4,uVar5,uVar6,uVar7,uVar8
         ,uVar9,uVar10,uVar11,uVar12);
LAB_0045d8b4:
  FUN_00407f30(balance_db_mutex);
  return 0;
}

