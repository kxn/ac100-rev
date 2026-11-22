// func radius_read_config @ 00447b74 size=860

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * radius_read_config(char *param_1)

{
  undefined4 *__s;
  void *__dest;
  FILE *__stream;
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  size_t sVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  char acStack_229 [517];
  
  __s = (undefined4 *)uac_mem_malloc_my(0x20,0xac);
  puVar8 = __s;
  if (__s != (undefined4 *)0x0) {
    memset(__s,0,0x20);
    __dest = (void *)uac_mem_malloc_my(0xe4,0x2f7);
    *__s = __dest;
    if (__dest != (void *)0x0) {
      memcpy(__dest,PTR_DAT_007591ac + 0x12b0,0xe4);
      __stream = fopen(param_1,"r");
      if (__stream != (FILE *)0x0) {
LAB_00447c54:
        do {
          do {
            pcVar1 = fgets(acStack_229 + 1,0x200,__stream);
            if (pcVar1 == (char *)0x0) {
              fclose(__stream);
              return __s;
            }
          } while (((acStack_229[1] == '\n') || (acStack_229[1] == '#')) || (acStack_229[1] == '\0')
                  );
          sVar2 = strlen(acStack_229 + 1);
          acStack_229[sVar2] = '\0';
          sVar2 = strcspn(acStack_229 + 1,"\t ");
          if (sVar2 == 0) break;
          (acStack_229 + 1)[sVar2] = '\0';
          iVar3 = _radius_find_option(__s,acStack_229 + 1,0xffffffff);
          iVar6 = ___ctype_b;
          if (iVar3 == 0) {
            if (radius_err_switch != 0) {
              uVar7 = 0x31d;
              pcVar1 = "[RADIUS_ERR]%s()/%d Unrecognized keyword: %s\n";
LAB_00447e98:
              printf(pcVar1,"radius_read_config",uVar7,acStack_229 + 1);
            }
            break;
          }
          if (*(int *)(iVar3 + 0x44) != 1) {
            if (radius_err_switch != 0) {
              uVar7 = 0x324;
              pcVar1 = "[RADIUS_ERR]%s()/%d Duplicate option line: %s\n";
              goto LAB_00447e98;
            }
            break;
          }
          pcVar1 = acStack_229 + sVar2 + 2;
          while ((*(ushort *)(___ctype_b + *pcVar1 * 2) & 0x20) != 0) {
            pcVar1 = pcVar1 + 1;
          }
          sVar2 = strlen(pcVar1);
          do {
            sVar4 = sVar2;
            sVar2 = sVar4 - 1;
            if ((int)sVar2 < 0) break;
          } while ((*(ushort *)(iVar6 + pcVar1[sVar2] * 2) & 0x20) != 0);
          pcVar1[sVar4] = '\0';
          if (*(int *)(iVar3 + 0x40) != 1) {
            if (*(int *)(iVar3 + 0x40) != 2) {
              if (radius_err_switch != 0) {
                printf("[RADIUS_ERR]%s()/%d rc_read_config: impossible case branch!\n",
                       "radius_read_config",0x348);
              }
                    /* WARNING: Subroutine does not return */
              abort();
            }
            piVar5 = (int *)uac_mem_malloc_my(4,0x121);
            if (piVar5 == (int *)0x0) break;
            iVar6 = atoi(pcVar1);
            *piVar5 = iVar6;
            *(int **)(iVar3 + 0x48) = piVar5;
            goto LAB_00447c54;
          }
          pcVar1 = strdup(pcVar1);
          *(char **)(iVar3 + 0x48) = pcVar1;
        } while (pcVar1 != (char *)0x0);
        fclose(__stream);
      }
    }
    puVar8 = (undefined4 *)0x0;
    _radius_rc_destroy(__s);
  }
  return puVar8;
}

