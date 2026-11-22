// func _wips_print_counter_info @ 004c7f38 size=396

void _wips_print_counter_info(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_348;
  undefined4 local_344;
  undefined4 local_340;
  undefined4 local_33c;
  undefined2 local_338;
  undefined4 local_334;
  undefined4 local_330;
  undefined4 local_32c;
  undefined4 local_328;
  undefined4 local_324;
  undefined4 local_320;
  undefined1 local_31c;
  undefined4 local_318 [192];
  
  iVar3 = 0;
  local_348 = 0;
  local_344 = 0;
  local_340 = 0;
  local_33c = 0;
  local_338 = 0;
  local_334 = 0;
  local_330 = 0;
  local_32c = 0;
  local_328 = 0;
  local_324 = 0;
  local_320 = 0;
  local_31c = 0;
  memset(local_318,0,0x300);
  wips_mac2str(param_1,&local_348);
  wips_time2str(*(undefined4 *)(param_1 + 0x2c),&local_334);
  printf("mac: %s\tcounter_time: %s\n",&local_348,&local_334);
  printf("channel: ");
  iVar1 = param_1;
  do {
    iVar3 = iVar3 + -4;
    printf("0x%08x ",*(undefined4 *)(iVar1 + 0x28));
    iVar1 = param_1 + iVar3;
  } while (iVar3 != -0x18);
  puVar4 = local_318;
  printf("\n\t");
  iVar1 = wips_channel_get(param_1 + 0x14,local_318);
  for (iVar3 = 0; iVar3 < iVar1; iVar3 = iVar3 + 1) {
    uVar2 = *puVar4;
    puVar4 = puVar4 + 1;
    printf("%d ",uVar2);
  }
  putchar(10);
  printf("wips_id: ");
  iVar1 = FUN_004081b0(param_1 + 8);
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0xc);
    while( true ) {
      printf("%d ",uVar2);
      iVar1 = FUN_00408680(iVar1);
      if (iVar1 == 0) break;
      uVar2 = *(undefined4 *)(iVar1 + 0xc);
    }
  }
  puts("\n");
  return;
}

