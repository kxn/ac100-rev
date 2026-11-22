// func sensor_test_simple_result_dump @ 005080f4 size=1380

void sensor_test_simple_result_dump(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  uVar7 = 0;
  FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
  puts("===========Simple Result =============");
  do {
    if (g_sensor_test_case_num_max <= uVar7) {
      puts("===============END=================");
      FUN_00407f30(l_sensor_test_db_mutex);
      return;
    }
    iVar3 = FUN_00407fe0(l_sensor_test_result_list + uVar7 * 0xc);
    if (iVar3 != 0) {
      printf("test case = %d:\n",uVar7);
      for (iVar3 = FUN_004081b0(l_sensor_test_result_list + uVar7 * 0xc); iVar3 != 0;
          iVar3 = FUN_00408680(iVar3)) {
        iVar6 = iVar3 + 0x48;
        printf("        bssid = %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n",(uint)*(byte *)(iVar3 + 0x3e),
               (uint)*(byte *)(iVar3 + 0x3f),(uint)*(byte *)(iVar3 + 0x40),
               (uint)*(byte *)(iVar3 + 0x41),(uint)*(byte *)(iVar3 + 0x42),
               (uint)*(byte *)(iVar3 + 0x43));
        printf("        ssid = %s\n",iVar3 + 0xc);
        printf("        sensor_id = %d\n",(uint)*(ushort *)(iVar3 + 0x44));
        iVar4 = FUN_00407fe0(iVar6);
        if (iVar4 != 0) {
          puts("            onboarding:");
          uVar5 = FUN_00407fe0(iVar6);
          printf("            cached result num = %d, the recent result is:\n",uVar5);
          uVar5 = FUN_00408610(iVar6);
          _print_simple_result_dump(uVar5);
          puts("            -----------------------");
        }
        iVar6 = iVar3 + 0x54;
        iVar4 = FUN_00407fe0(iVar6);
        if (iVar4 != 0) {
          puts("            dns:");
          uVar5 = FUN_00407fe0(iVar6);
          printf("            cached result num = %d, the recent result is:\n",uVar5);
          uVar5 = FUN_00408610(iVar6);
          _print_simple_result_dump(uVar5);
          puts("            -----------------------");
        }
        iVar6 = iVar3 + 0x60;
        iVar4 = FUN_00407fe0(iVar6);
        if (iVar4 != 0) {
          puts("            radius:");
          uVar5 = FUN_00407fe0(iVar6);
          printf("            cached result num = %d, the recent result is:\n",uVar5);
          uVar5 = FUN_00408610(iVar6);
          _print_simple_result_dump(uVar5);
          puts("            -----------------------");
        }
        iVar6 = iVar3 + 0x6c;
        iVar4 = FUN_00407fe0(iVar6);
        if (iVar4 != 0) {
          puts("            speed:");
          uVar5 = FUN_00407fe0(iVar6);
          printf("            cached result num = %d, the recent result is:\n",uVar5);
          uVar5 = FUN_00408610(iVar6);
          _print_simple_result_dump(uVar5);
          puts("            -----------------------");
        }
        iVar6 = iVar3 + 0x78;
        iVar4 = FUN_00407fe0(iVar6);
        if (iVar4 == 0) {
          cVar2 = *(char *)(iVar3 + 0x95);
        }
        else {
          puts("            delayloss:");
          uVar5 = FUN_00407fe0(iVar6);
          printf("            cached result num = %d, the recent result is:\n",uVar5);
          uVar5 = FUN_00408610(iVar6);
          _print_simple_result_dump(uVar5);
          puts("            -----------------------");
          cVar2 = *(char *)(iVar3 + 0x95);
        }
        iVar4 = 0;
        if (cVar2 != '\0') {
          do {
            bVar1 = *(byte *)(iVar3 + 0x95);
            while( true ) {
              if ((int)(uint)bVar1 <= iVar4) {
                cVar2 = *(char *)(iVar3 + 0x96);
                goto LAB_005082ec;
              }
              iVar8 = iVar4 * 0xc;
              iVar6 = FUN_00407fe0(*(int *)(iVar3 + 0x84) + iVar8);
              if (iVar6 == 0) break;
              printf("            hostaccess config_%d:\n",iVar4);
              uVar5 = FUN_00407fe0(*(int *)(iVar3 + 0x84) + iVar8);
              printf("            cached result num = %d, the recent result is:\n",uVar5);
              uVar5 = FUN_00408610(*(int *)(iVar3 + 0x84) + iVar8);
              _print_simple_result_dump(uVar5);
              puts("            -----------------------");
              bVar1 = *(byte *)(iVar3 + 0x95);
              iVar4 = iVar4 + 1;
            }
            iVar4 = iVar4 + 1;
          } while( true );
        }
        cVar2 = *(char *)(iVar3 + 0x96);
LAB_005082ec:
        iVar4 = 0;
        if (cVar2 != '\0') {
          do {
            bVar1 = *(byte *)(iVar3 + 0x96);
            while( true ) {
              if ((int)(uint)bVar1 <= iVar4) {
                cVar2 = *(char *)(iVar3 + 0x97);
                goto LAB_00508384;
              }
              iVar8 = iVar4 * 0xc;
              iVar6 = FUN_00407fe0(*(int *)(iVar3 + 0x88) + iVar8);
              if (iVar6 == 0) break;
              printf("            mail config_%d:\n",iVar4);
              uVar5 = FUN_00407fe0(*(int *)(iVar3 + 0x88) + iVar8);
              printf("            cached result num = %d, the recent result is:\n",uVar5);
              uVar5 = FUN_00408610(*(int *)(iVar3 + 0x88) + iVar8);
              _print_simple_result_dump(uVar5);
              puts("            -----------------------");
              bVar1 = *(byte *)(iVar3 + 0x96);
              iVar4 = iVar4 + 1;
            }
            iVar4 = iVar4 + 1;
          } while( true );
        }
        cVar2 = *(char *)(iVar3 + 0x97);
LAB_00508384:
        iVar4 = 0;
        if (cVar2 != '\0') {
          do {
            bVar1 = *(byte *)(iVar3 + 0x97);
            while( true ) {
              if ((int)(uint)bVar1 <= iVar4) {
                cVar2 = *(char *)(iVar3 + 0x98);
                goto LAB_0050841c;
              }
              iVar8 = iVar4 * 0xc;
              iVar6 = FUN_00407fe0(*(int *)(iVar3 + 0x8c) + iVar8);
              if (iVar6 == 0) break;
              printf("            web config_%d:\n",iVar4);
              uVar5 = FUN_00407fe0(*(int *)(iVar3 + 0x8c) + iVar8);
              printf("            cached result num = %d, the recent result is:\n",uVar5);
              uVar5 = FUN_00408610(*(int *)(iVar3 + 0x8c) + iVar8);
              _print_simple_result_dump(uVar5);
              puts("            -----------------------");
              bVar1 = *(byte *)(iVar3 + 0x97);
              iVar4 = iVar4 + 1;
            }
            iVar4 = iVar4 + 1;
          } while( true );
        }
        cVar2 = *(char *)(iVar3 + 0x98);
LAB_0050841c:
        iVar4 = 0;
        if (cVar2 != '\0') {
          do {
            bVar1 = *(byte *)(iVar3 + 0x98);
            while( true ) {
              if ((int)(uint)bVar1 <= iVar4) goto LAB_005084b4;
              iVar8 = iVar4 * 0xc;
              iVar6 = FUN_00407fe0(*(int *)(iVar3 + 0x90) + iVar8);
              if (iVar6 == 0) break;
              printf("            ftp config_%d:\n",iVar4);
              iVar4 = iVar4 + 1;
              uVar5 = FUN_00407fe0(*(int *)(iVar3 + 0x90) + iVar8);
              printf("            cached result num = %d, the recent result is:\n",uVar5);
              uVar5 = FUN_00408610(*(int *)(iVar3 + 0x90) + iVar8);
              _print_simple_result_dump(uVar5);
              puts("            -----------------------");
              bVar1 = *(byte *)(iVar3 + 0x98);
            }
            iVar4 = iVar4 + 1;
          } while( true );
        }
LAB_005084b4:
      }
    }
    uVar7 = uVar7 + 1;
  } while( true );
}

