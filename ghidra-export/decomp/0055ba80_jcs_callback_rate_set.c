// func jcs_callback_rate_set @ 0055ba80 size=4000

void jcs_callback_rate_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined4 local_68 [16];
  
  memset(local_68,0,0x40);
  if (rate_debug_switch != 0) {
    uVar4 = json_object_to_json_string_ext(param_1,0);
    printf("[RATE_DBG]%s()/%d get jcs :%s\n","jcs_callback_rate_set",0x46,uVar4);
  }
  iVar1 = json_object_object_get(param_1,"rate_11a");
  if (iVar1 != 0) {
    iVar2 = json_object_object_get(iVar1,"11a_base");
    if (iVar2 != 0) {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 5) {
        puVar7 = local_68;
        for (iVar3 = 0; iVar5 = json_object_array_length(iVar2), iVar3 < iVar5; iVar3 = iVar3 + 1) {
          if (iVar3 == 0x10) {
            iVar3 = 0x10;
            break;
          }
          iVar5 = json_object_array_get_idx(iVar2,iVar3);
          if (iVar5 == 0) {
LAB_0055c370:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "jcs_callback_rate_set",0x4e);
            }
            *puVar7 = 0xffffffff;
          }
          else {
            iVar6 = json_object_get_type(iVar5);
            if (iVar6 == 3) {
              uVar4 = json_object_get_int(iVar5);
              *puVar7 = uVar4;
            }
            else {
              iVar6 = json_object_get_type();
              if (iVar6 != 2) goto LAB_0055c370;
              uVar8 = json_object_get_double(iVar5);
              uVar4 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
              *puVar7 = uVar4;
            }
          }
          puVar7 = puVar7 + 1;
        }
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 4) {
          iVar2 = json_object_object_length(iVar2);
          iVar3 = 0;
          if (iVar2 == 0) goto LAB_0055bb38;
        }
        iVar3 = 0;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n"
                 ,"jcs_callback_rate_set",0x4e);
        }
      }
LAB_0055bb38:
      rate_db_11a_mandatory_rate_set(local_68,iVar3);
    }
    iVar2 = json_object_object_get(iVar1,"11a_supp");
    if (iVar2 != 0) {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 5) {
        puVar7 = local_68;
        for (iVar3 = 0; iVar5 = json_object_array_length(iVar2), iVar3 < iVar5; iVar3 = iVar3 + 1) {
          if (iVar3 == 0x10) {
            iVar3 = 0x10;
            break;
          }
          iVar5 = json_object_array_get_idx(iVar2,iVar3);
          if (iVar5 == 0) {
LAB_0055c228:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "jcs_callback_rate_set",0x54);
            }
            *puVar7 = 0xffffffff;
          }
          else {
            iVar6 = json_object_get_type(iVar5);
            if (iVar6 == 3) {
              uVar4 = json_object_get_int(iVar5);
              *puVar7 = uVar4;
            }
            else {
              iVar6 = json_object_get_type();
              if (iVar6 != 2) goto LAB_0055c228;
              uVar8 = json_object_get_double(iVar5);
              uVar4 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
              *puVar7 = uVar4;
            }
          }
          puVar7 = puVar7 + 1;
        }
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 4) {
          iVar2 = json_object_object_length(iVar2);
          iVar3 = 0;
          if (iVar2 == 0) goto LAB_0055bb90;
        }
        iVar3 = 0;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n"
                 ,"jcs_callback_rate_set",0x54);
        }
      }
LAB_0055bb90:
      rate_db_11a_supported_rate_set(local_68,iVar3);
    }
    iVar1 = json_object_object_get(iVar1,"11a_mult");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar4 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar8 = json_object_get_double(iVar1);
          uVar4 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
        }
        else {
          uVar4 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_callback_rate_set",0x5b);
          }
        }
      }
      rate_db_11a_multicast_rate_set(uVar4);
    }
  }
  iVar1 = json_object_object_get(param_1,"rate_11b");
  if (iVar1 != 0) {
    iVar2 = json_object_object_get(iVar1,"11b_base");
    if (iVar2 != 0) {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 5) {
        puVar7 = local_68;
        for (iVar3 = 0; iVar5 = json_object_array_length(iVar2), iVar3 < iVar5; iVar3 = iVar3 + 1) {
          if (iVar3 == 0x10) {
            iVar3 = 0x10;
            break;
          }
          iVar5 = json_object_array_get_idx(iVar2,iVar3);
          if (iVar5 == 0) {
LAB_0055c414:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "jcs_callback_rate_set",0x66);
            }
            *puVar7 = 0xffffffff;
          }
          else {
            iVar6 = json_object_get_type(iVar5);
            if (iVar6 == 3) {
              uVar4 = json_object_get_int(iVar5);
              *puVar7 = uVar4;
            }
            else {
              iVar6 = json_object_get_type();
              if (iVar6 != 2) goto LAB_0055c414;
              uVar8 = json_object_get_double(iVar5);
              uVar4 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
              *puVar7 = uVar4;
            }
          }
          puVar7 = puVar7 + 1;
        }
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 4) {
          iVar2 = json_object_object_length(iVar2);
          iVar3 = 0;
          if (iVar2 == 0) goto LAB_0055bc58;
        }
        iVar3 = 0;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n"
                 ,"jcs_callback_rate_set",0x66);
        }
      }
LAB_0055bc58:
      rate_db_11b_mandatory_rate_set(local_68,iVar3);
    }
    iVar2 = json_object_object_get(iVar1,"11b_supp");
    if (iVar2 != 0) {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 5) {
        puVar7 = local_68;
        for (iVar3 = 0; iVar5 = json_object_array_length(iVar2), iVar3 < iVar5; iVar3 = iVar3 + 1) {
          if (iVar3 == 0x10) {
            iVar3 = 0x10;
            break;
          }
          iVar5 = json_object_array_get_idx(iVar2,iVar3);
          if (iVar5 == 0) {
LAB_0055c184:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "jcs_callback_rate_set",0x6d);
            }
            *puVar7 = 0xffffffff;
          }
          else {
            iVar6 = json_object_get_type(iVar5);
            if (iVar6 == 3) {
              uVar4 = json_object_get_int(iVar5);
              *puVar7 = uVar4;
            }
            else {
              iVar6 = json_object_get_type();
              if (iVar6 != 2) goto LAB_0055c184;
              uVar8 = json_object_get_double(iVar5);
              uVar4 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
              *puVar7 = uVar4;
            }
          }
          puVar7 = puVar7 + 1;
        }
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 4) {
          iVar2 = json_object_object_length(iVar2);
          iVar3 = 0;
          if (iVar2 == 0) goto LAB_0055bcb0;
        }
        iVar3 = 0;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n"
                 ,"jcs_callback_rate_set",0x6d);
        }
      }
LAB_0055bcb0:
      rate_db_11b_supported_rate_set(local_68,iVar3);
    }
    iVar1 = json_object_object_get(iVar1,"11b_mult");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar4 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar8 = json_object_get_double(iVar1);
          uVar4 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
        }
        else {
          uVar4 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_callback_rate_set",0x74);
          }
        }
      }
      rate_db_11b_multicast_rate_set(uVar4);
    }
  }
  iVar1 = json_object_object_get(param_1,"rate_11g");
  if (iVar1 == 0) goto LAB_0055be30;
  iVar2 = json_object_object_get(iVar1,"11g_base");
  if (iVar2 != 0) {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 5) {
      puVar7 = local_68;
      for (iVar3 = 0; iVar5 = json_object_array_length(iVar2), iVar3 < iVar5; iVar3 = iVar3 + 1) {
        if (iVar3 == 0x10) {
          iVar3 = 0x10;
          break;
        }
        iVar5 = json_object_array_get_idx(iVar2,iVar3);
        if (iVar5 == 0) {
LAB_0055c4b8:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_callback_rate_set",0x7f);
          }
          *puVar7 = 0xffffffff;
        }
        else {
          iVar6 = json_object_get_type(iVar5);
          if (iVar6 == 3) {
            uVar4 = json_object_get_int(iVar5);
            *puVar7 = uVar4;
          }
          else {
            iVar6 = json_object_get_type();
            if (iVar6 != 2) goto LAB_0055c4b8;
            uVar8 = json_object_get_double(iVar5);
            uVar4 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
            *puVar7 = uVar4;
          }
        }
        puVar7 = puVar7 + 1;
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 4) {
        iVar2 = json_object_object_length(iVar2);
        iVar3 = 0;
        if (iVar2 == 0) goto LAB_0055bd78;
      }
      iVar3 = 0;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
               "jcs_callback_rate_set",0x7f);
      }
    }
LAB_0055bd78:
    rate_db_11g_mandatory_rate_set(local_68,iVar3);
  }
  iVar2 = json_object_object_get(iVar1,"11g_supp");
  if (iVar2 != 0) {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 5) {
      puVar7 = local_68;
      for (iVar3 = 0; iVar5 = json_object_array_length(iVar2), iVar3 < iVar5; iVar3 = iVar3 + 1) {
        if (iVar3 == 0x10) {
          iVar3 = 0x10;
          break;
        }
        iVar5 = json_object_array_get_idx(iVar2,iVar3);
        if (iVar5 == 0) {
LAB_0055c2cc:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_callback_rate_set",0x86);
          }
          *puVar7 = 0xffffffff;
        }
        else {
          iVar6 = json_object_get_type(iVar5);
          if (iVar6 == 3) {
            uVar4 = json_object_get_int(iVar5);
            *puVar7 = uVar4;
          }
          else {
            iVar6 = json_object_get_type();
            if (iVar6 != 2) goto LAB_0055c2cc;
            uVar8 = json_object_get_double(iVar5);
            uVar4 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
            *puVar7 = uVar4;
          }
        }
        puVar7 = puVar7 + 1;
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 4) {
        iVar2 = json_object_object_length(iVar2);
        iVar3 = 0;
        if (iVar2 == 0) goto LAB_0055bdd0;
      }
      iVar3 = 0;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
               "jcs_callback_rate_set",0x86);
      }
    }
LAB_0055bdd0:
    rate_db_11g_supported_rate_set(local_68,iVar3);
  }
  iVar1 = json_object_object_get(iVar1,"11g_mult");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar4 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar8 = json_object_get_double(iVar1);
        uVar4 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
      }
      else {
        uVar4 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "jcs_callback_rate_set",0x8d);
        }
      }
    }
    rate_db_11g_multicast_rate_set(uVar4);
  }
LAB_0055be30:
  iVar1 = json_object_object_get(param_1,"rate_11n");
  if (iVar1 != 0) {
    iVar2 = json_object_object_get(iVar1,"11n_base");
    if (iVar2 != 0) {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar4 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 == 2) {
          uVar8 = json_object_get_double(iVar2);
          uVar4 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
        }
        else {
          uVar4 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_callback_rate_set",0x98);
          }
        }
      }
      rate_db_11n_mandatory_mcs_set(uVar4);
    }
    iVar1 = json_object_object_get(iVar1,"11n_supp");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar4 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar8 = json_object_get_double(iVar1);
          uVar4 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
        }
        else {
          uVar4 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_callback_rate_set",0x9f);
          }
        }
      }
      rate_db_11n_supported_mcs_set(uVar4);
    }
  }
  iVar1 = json_object_object_get(param_1,"rate_11ac");
  if (iVar1 != 0) {
    iVar2 = json_object_object_get(iVar1,"11ac_base");
    if (iVar2 != 0) {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar4 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 == 2) {
          uVar8 = json_object_get_double(iVar2);
          uVar4 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
        }
        else {
          uVar4 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_callback_rate_set",0xaa);
          }
        }
      }
      rate_db_11ac_mandatory_nss_set(uVar4);
    }
    iVar1 = json_object_object_get(iVar1,"11ac_supp");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar4 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar8 = json_object_get_double(iVar1);
          uVar4 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
        }
        else {
          uVar4 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_callback_rate_set",0xb1);
          }
        }
      }
      rate_db_11ac_supported_nss_set(uVar4);
    }
  }
  iVar1 = json_object_object_get(param_1,"rate_11ax");
  if (iVar1 != 0) {
    iVar2 = json_object_object_get(iVar1,"11ax_base");
    if (iVar2 != 0) {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar4 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 == 2) {
          uVar8 = json_object_get_double(iVar2);
          uVar4 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
        }
        else {
          uVar4 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_callback_rate_set",0xbc);
          }
        }
      }
      rate_db_11ax_mandatory_nss_set(uVar4);
    }
    iVar1 = json_object_object_get(iVar1,"11ax_supp");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar4 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar8 = json_object_get_double(iVar1);
          uVar4 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
        }
        else {
          uVar4 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_callback_rate_set",0xc3);
          }
        }
      }
      rate_db_11ax_supported_nss_set(uVar4);
    }
  }
  transfer_rcc_db_to_rcc_md5();
  if (rate_debug_switch != 0) {
    printf("[RATE_DBG]%s()/%d set rate configure to uci successfully\n","jcs_callback_rate_set",0xca
          );
  }
  return;
}

