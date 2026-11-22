// func radius_read_dictionary @ 004481ec size=3436

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 radius_read_dictionary(int param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  size_t sVar2;
  char *pcVar3;
  FILE *__stream;
  char *pcVar4;
  int iVar5;
  void *pvVar6;
  char cVar7;
  char **ppcVar8;
  undefined4 uVar9;
  char *__s2;
  undefined **ppuVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined *puVar14;
  char *local_268 [16];
  char local_228 [256];
  char acStack_128 [256];
  
  if ((param_2 == (char *)0x0) || (param_3 == (char *)0x0)) {
    if (radius_err_switch != 0) {
      uVar9 = 0x3a2;
      pcVar4 = "[RADIUS_ERR]%s()/%d Dictionary file error\n";
LAB_00448430:
      printf(pcVar4,"radius_read_dictionary",uVar9);
      return 0xffffffff;
    }
  }
  else {
    if (radius_info_switch != 0) {
      printf("[RADIUS_INFO]%s()/%d Dictionary dir: %s, filename: %s\n","radius_read_dictionary",
             0x3a6,param_2,param_3);
    }
    sVar1 = strlen(param_3);
    if ((sVar1 < 0x80) && (sVar2 = strlen(param_2), sVar2 < 0x80)) {
      pcVar3 = strrchr(param_3,0x2f);
      pcVar4 = param_3;
      if (pcVar3 == (char *)0x0) {
        if ((*param_2 != '\0') && (iVar13 = strcmp(param_2,"."), iVar13 != 0)) {
          pcVar4 = acStack_128;
          snprintf(acStack_128,0x100,"%s/%s",param_2,param_3);
        }
      }
      else {
        param_2 = acStack_128;
        strcpy(acStack_128,param_3);
        pcVar3[(int)(acStack_128 + -(int)param_3)] = '\0';
      }
      if (radius_info_switch != 0) {
        printf("[RADIUS_INFO]%s()/%d Open dictionary file: %s\n","radius_read_dictionary",0x3bf,
               pcVar4);
      }
      iVar13 = 0;
      __stream = fopen(pcVar4,"r");
      if (__stream != (FILE *)0x0) {
LAB_00448300:
        do {
          pcVar4 = fgets(local_228,0x100,__stream);
          if (pcVar4 == (char *)0x0) {
            fclose(__stream);
            return 0;
          }
        } while ((((local_228[0] == '#') || (local_228[0] == '\0')) || (local_228[0] == '\n')) ||
                (local_228[0] == '\r'));
        pcVar4 = strchr(local_228,0x23);
        if (pcVar4 != (char *)0x0) {
          *pcVar4 = '\0';
        }
        ppcVar8 = local_268;
        iVar11 = 0;
        pcVar4 = local_228;
LAB_0044837c:
        cVar7 = *pcVar4;
LAB_00448380:
        pcVar3 = local_268[0];
        if (cVar7 == '\0') goto LAB_00448534;
        if (iVar11 != 0x10) {
          if (cVar7 != '#') {
            do {
              cVar7 = *pcVar4;
              if (cVar7 == ' ') {
                *pcVar4 = '\0';
              }
              else if (cVar7 == '\t') {
                *pcVar4 = '\0';
              }
              else if (cVar7 == '\r') {
                *pcVar4 = '\0';
              }
              else {
                if (cVar7 != '\n') goto LAB_00448494;
                *pcVar4 = '\0';
              }
              pcVar4 = pcVar4 + 1;
            } while( true );
          }
          *pcVar4 = '\0';
          goto LAB_00448534;
        }
        goto LAB_00448548;
      }
      if (radius_err_switch != 0) {
        uVar9 = 0x3c3;
        pcVar4 = "[RADIUS_ERR]%s()/%d Open dictionary file error\n";
        goto LAB_00448430;
      }
    }
    else if (radius_err_switch != 0) {
      printf("[RADIUS_ERR]%s()/%d Dictionary filename is too long: %d\n","radius_read_dictionary",
             0x3ab,sVar1);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
LAB_00448494:
  if (cVar7 == '\0') {
LAB_00448534:
    if (iVar11 == 0) goto LAB_00448300;
    if (iVar11 == 1) {
      if (radius_err_switch == 0) goto LAB_004486d8;
      uVar9 = 0x3e3;
      pcVar4 = "[RADIUS_ERR]%s()/%d Invalid entry\n";
      pcVar3 = "radius_read_dictionary";
      goto LAB_004486fc;
    }
LAB_00448548:
    iVar5 = strcasecmp(local_268[0],"VALUE");
    if (iVar5 == 0) goto LAB_00448300;
    iVar5 = strcasecmp(pcVar3,"ATTRIBUTE");
    if (iVar5 == 0) {
      if (1 < iVar11 - 4U) {
        if (radius_err_switch == 0) goto LAB_004486d8;
        uVar9 = 0x268;
        pcVar4 = "[RADIUS_ERR]%s()/%d Invalid ATTRIBUTE line\n";
        pcVar3 = "_radius_process_attribute";
        goto LAB_004486fc;
      }
      if ((*local_268[2] == '0') && ((local_268[2][1] == 'x' || (local_268[2][1] == 'X')))) {
        pcVar4 = local_268[2] + 2;
        sVar1 = 0x10;
        pcVar3 = "0123456789abcdef";
      }
      else {
        sVar1 = 10;
        pcVar3 = "0123456789";
        pcVar4 = local_268[2];
      }
      uVar12 = 0;
      goto LAB_004488c0;
    }
    iVar5 = strcasecmp(pcVar3,"$INCLUDE");
    if (iVar5 == 0) {
      iVar11 = radius_read_dictionary(param_1,param_2,local_268[1]);
      if (iVar11 == 0) goto LAB_00448300;
      goto LAB_004486d8;
    }
    iVar5 = strcasecmp(pcVar3,"VALUE-ALIAS");
    if (iVar5 == 0) goto LAB_00448300;
    iVar5 = strcasecmp(pcVar3,"VENDOR");
    if (iVar5 != 0) {
      iVar5 = strcasecmp(pcVar3,"BEGIN-TLV");
      if ((iVar5 == 0) || (iVar5 = strcasecmp(pcVar3,"END-TLV"), iVar5 == 0)) goto LAB_00448300;
      iVar5 = strcasecmp(pcVar3,"BEGIN-VENDOR");
      __s2 = local_268[1];
      if (iVar5 == 0) {
        if (iVar11 != 2) {
          if (radius_err_switch == 0) goto LAB_004486d8;
          uVar9 = 0x42c;
          pcVar4 = "[RADIUS_ERR]%s()/%d Invalid BEGIN-VENDOR entry\n";
          pcVar3 = "radius_read_dictionary";
          goto LAB_004486fc;
        }
        iVar13 = radius_dict_getvendproc_by_name(param_1,local_268[1]);
        if (iVar13 != 0) goto LAB_00448300;
        if (radius_err_switch == 0) goto LAB_004486d8;
        uVar9 = 0x434;
        pcVar4 = "[RADIUS_ERR]%s()/%d Unknown vendor name: %s\n";
      }
      else {
        iVar5 = strcasecmp(pcVar3,"END-VENDOR");
        __s2 = local_268[1];
        if (iVar5 == 0) {
          if (iVar11 != 2) {
            if (radius_err_switch == 0) goto LAB_004486d8;
            uVar9 = 0x440;
            pcVar4 = "[RADIUS_ERR]%s()/%d Invalid END-VENDOR entry\n";
            pcVar3 = "radius_read_dictionary";
            goto LAB_004486fc;
          }
          iVar11 = radius_dict_getvendproc_by_name(param_1,local_268[1]);
          if (iVar11 == 0) {
            if (radius_err_switch == 0) goto LAB_004486d8;
            uVar9 = 0x448;
            pcVar4 = "[RADIUS_ERR]%s()/%d Unknown vendor name: %s\n";
          }
          else {
            if (iVar11 == iVar13) {
              iVar13 = 0;
              goto LAB_00448300;
            }
            if (radius_err_switch == 0) goto LAB_004486d8;
            uVar9 = 0x44f;
            pcVar4 = "[RADIUS_ERR]%s()/%d END-VENDOR %s does not match any previous BEGIN-VENDOR\n";
          }
        }
        else {
          if (radius_err_switch == 0) goto LAB_004486d8;
          uVar9 = 0x45b;
          pcVar4 = "[RADIUS_ERR]%s()/%d Invalid keyword \"%s\"\n";
          __s2 = pcVar3;
        }
      }
      pcVar3 = "radius_read_dictionary";
      goto LAB_004489b8;
    }
    if (1 < iVar11 - 3U) {
      if (radius_err_switch == 0) goto LAB_004486d8;
      uVar9 = 0x2cb;
      pcVar4 = "[RADIUS_ERR]%s()/%d Invalid VENDOR entry\n";
      pcVar3 = "_radius_process_vendor";
      goto LAB_004486fc;
    }
    if ((*(ushort *)(___ctype_b + *local_268[2] * 2) & 8) == 0) {
      if (radius_err_switch == 0) goto LAB_004486d8;
      uVar9 = 0x2d4;
      pcVar4 = "[RADIUS_ERR]%s()/%d Invalid value\n";
      pcVar3 = "_radius_process_vendor";
      goto LAB_004486fc;
    }
    iVar11 = atoi(local_268[2]);
    if (radius_info_switch != 0) {
      printf("[RADIUS_INFO]%s()/%d Get vendor: name: %s, value: %d\n","_radius_process_vendor",0x2d9
             ,local_268[1],iVar11);
    }
    pcVar4 = local_268[1];
    if (0xffff < iVar11) {
      if (radius_err_switch == 0) goto LAB_004486d8;
      uVar9 = 0x297;
      pcVar4 = "[RADIUS_ERR]%s()/%d Cannot handle vendor ID larger than 65535\n";
      pcVar3 = "_radius_dict_addvend";
      goto LAB_004486fc;
    }
    sVar1 = strlen(local_268[1]);
    if (0x40 < sVar1) {
      if (radius_err_switch == 0) goto LAB_004486d8;
      uVar9 = 0x29d;
      pcVar4 = "[RADIUS_ERR]%s()/%d Vendor name too long\n";
      pcVar3 = "_radius_dict_addvend";
      goto LAB_004486fc;
    }
    pcVar3 = (char *)uac_mem_malloc_my(0x48,0x2a1);
    if (pcVar3 == (char *)0x0) {
      if (radius_err_switch == 0) goto LAB_004486d8;
      uVar9 = 0x2a3;
      pcVar4 = "[RADIUS_ERR]%s()/%d Out of memory\n";
      pcVar3 = "_radius_dict_addvend";
      goto LAB_004486fc;
    }
    strcpy(pcVar3,pcVar4);
    *(int *)(pcVar3 + 0x44) = iVar11;
    iVar11 = uac_hash_add(*(undefined4 *)(param_1 + 0x14),pcVar3);
    if (iVar11 == 0) {
      iVar11 = uac_hash_add(*(undefined4 *)(param_1 + 0x1c),pcVar3);
      if (iVar11 == 0) goto LAB_00448300;
      if (radius_err_switch != 0) {
        printf("[RADIUS_ERR]%s()/%d Add vendor hash table name fail\n","_radius_dict_addvend",0x2b7)
        ;
      }
      uac_hash_remove(*(undefined4 *)(param_1 + 0x14),pcVar3);
    }
    else if (radius_err_switch != 0) {
      printf("[RADIUS_ERR]%s()/%d Add vendor hash table value fail\n","_radius_dict_addvend",0x2ac);
    }
    uac_mem_free_my(pcVar3);
    goto LAB_004486d8;
  }
  *ppcVar8 = pcVar4;
  iVar11 = iVar11 + 1;
  for (; cVar7 = *pcVar4, cVar7 != '\0'; pcVar4 = pcVar4 + 1) {
    if (cVar7 == ' ') {
      ppcVar8 = ppcVar8 + 1;
      goto LAB_0044837c;
    }
    if (cVar7 == '\t') {
      ppcVar8 = ppcVar8 + 1;
      goto LAB_0044837c;
    }
    if (cVar7 == '\r') {
      ppcVar8 = ppcVar8 + 1;
      goto LAB_0044837c;
    }
    if (cVar7 == '\n') {
      ppcVar8 = ppcVar8 + 1;
      goto LAB_0044837c;
    }
  }
  ppcVar8 = ppcVar8 + 1;
  cVar7 = '\0';
  goto LAB_00448380;
LAB_004488c0:
  __s2 = local_268[3];
  if (*pcVar4 == 0) goto code_r0x004488cc;
  iVar11 = tolower((int)*pcVar4);
  pvVar6 = memchr(pcVar3,iVar11,sVar1);
  if (pvVar6 == (void *)0x0) {
    if (radius_err_switch == 0) goto LAB_004486d8;
    uVar9 = 0x271;
    pcVar4 = "[RADIUS_ERR]%s()/%d Invalid value\n";
    pcVar3 = "_radius_process_attribute";
    goto LAB_004486fc;
  }
  pcVar4 = pcVar4 + 1;
  uVar12 = (int)pvVar6 + (uVar12 * sVar1 - (int)pcVar3);
  goto LAB_004488c0;
code_r0x004488cc:
  ppuVar10 = &dict_attr_types;
  while( true ) {
    if (*ppuVar10 == (char *)0x0) goto LAB_004488fc;
    iVar11 = strcasecmp(*ppuVar10,__s2);
    pcVar4 = local_268[1];
    if (iVar11 == 0) break;
    ppuVar10 = ppuVar10 + 2;
  }
  puVar14 = ppuVar10[1];
  if ((int)puVar14 < 0) {
LAB_004488fc:
    if (radius_err_switch != 0) {
      uVar9 = 0x27b;
      pcVar4 = "[RADIUS_ERR]%s()/%d Invalid type \"%s\"\n";
      pcVar3 = "_radius_process_attribute";
LAB_004489b8:
      printf(pcVar4,pcVar3,uVar9,__s2);
    }
    goto LAB_004486d8;
  }
  sVar1 = strlen(local_268[1]);
  pcVar3 = pcVar4;
  if (sVar1 < 0x41) {
    for (; cVar7 = *pcVar3, cVar7 != '\0'; pcVar3 = pcVar3 + 1) {
      if (cVar7 < ' ') {
        if (radius_err_switch == 0) goto LAB_004486d8;
        uVar9 = 0x1f0;
        pcVar4 = "[RADIUS_ERR]%s()/%d Attribute name cannot contain control characters\n";
        pcVar3 = "_radius_dict_addattr";
        goto LAB_004486fc;
      }
      if ((cVar7 == '\"') || (cVar7 == '\\')) {
        if (radius_err_switch == 0) goto LAB_004486d8;
        uVar9 = 0x1f6;
        pcVar4 = "[RADIUS_ERR]%s()/%d Attribute name cannot contain quotation or backslash\n";
        pcVar3 = "_radius_dict_addattr";
        goto LAB_004486fc;
      }
      if (((cVar7 == '<') || (cVar7 == '>')) || (cVar7 == '&')) {
        if (radius_err_switch == 0) goto LAB_004486d8;
        uVar9 = 0x1fc;
        pcVar4 = "[RADIUS_ERR]%s()/%d Attribute name cannot contain XML control characters\n";
        pcVar3 = "_radius_dict_addattr";
        goto LAB_004486fc;
      }
    }
    if ((int)uVar12 < 0) {
      if (radius_err_switch == 0) goto LAB_004486d8;
      uVar9 = 0x203;
      pcVar4 = "[RADIUS_ERR]%s()/%d ATTRIBUTE has invalid number (less than zero)\n";
      pcVar3 = "_radius_dict_addattr";
    }
    else if ((int)uVar12 < 0x10000) {
      if (((iVar13 == 0) || ((DAT_00766bb0 != 0 && (iVar13 == *(int *)(DAT_00766bb0 + 0x44))))) ||
         (DAT_00766bb0 = radius_dict_getvend_by_value(param_1,iVar13), DAT_00766bb0 != 0)) {
        pvVar6 = (void *)uac_mem_malloc_my(0x50,0x22f);
        if (pvVar6 == (void *)0x0) {
          if (radius_err_switch == 0) goto LAB_004486d8;
          uVar9 = 0x231;
          pcVar4 = "[RADIUS_ERR]%s()/%d Out of memory\n";
          pcVar3 = "_radius_dict_addattr";
        }
        else {
          memcpy(pvVar6,pcVar4,sVar1);
          *(undefined1 *)((int)pvVar6 + sVar1) = 0;
          *(uint *)((int)pvVar6 + 0x44) = uVar12 | iVar13 << 0x10;
          *(int *)((int)pvVar6 + 0x4c) = iVar13;
          *(undefined **)((int)pvVar6 + 0x48) = puVar14;
          iVar11 = uac_hash_add(*(undefined4 *)(param_1 + 0x10),pvVar6);
          if (iVar11 == 0) {
            iVar11 = uac_hash_add(*(undefined4 *)(param_1 + 0x18),pvVar6);
            if (iVar11 == 0) {
              if (((iVar13 == 0) && (uVar12 != 0)) && ((int)uVar12 < 0x100)) {
                (&radius_dict_base_attrs)[uVar12] = pvVar6;
              }
              goto LAB_00448300;
            }
            uac_hash_remove(*(undefined4 *)(param_1 + 0x10),pvVar6);
            uac_mem_free_my(pvVar6);
            if (radius_err_switch == 0) goto LAB_004486d8;
            uVar9 = 0x251;
            pcVar4 = "[RADIUS_ERR]%s()/%d Add hash table name error\n";
            pcVar3 = "_radius_dict_addattr";
          }
          else {
            uac_mem_free_my(pvVar6);
            if (radius_err_switch == 0) goto LAB_004486d8;
            uVar9 = 0x245;
            pcVar4 = "[RADIUS_ERR]%s()/%d Add hash table value error\n";
            pcVar3 = "_radius_dict_addattr";
          }
        }
      }
      else {
        if (radius_err_switch == 0) goto LAB_004486d8;
        uVar9 = 0x227;
        pcVar4 = "[RADIUS_ERR]%s()/%d Unknown vendor\n";
        pcVar3 = "_radius_dict_addattr";
      }
    }
    else {
      if (radius_err_switch == 0) goto LAB_004486d8;
      uVar9 = 0x209;
      pcVar4 = "[RADIUS_ERR]%s()/%d ATTRIBUTE has invalid number (larger than 65535).\n";
      pcVar3 = "_radius_dict_addattr";
    }
  }
  else {
    if (radius_err_switch == 0) goto LAB_004486d8;
    uVar9 = 0x1e9;
    pcVar4 = "[RADIUS_ERR]%s()/%d Attribute name too long\n";
    pcVar3 = "_radius_dict_addattr";
  }
LAB_004486fc:
  printf(pcVar4,pcVar3,uVar9);
LAB_004486d8:
  fclose(__stream);
  return 0xffffffff;
}

