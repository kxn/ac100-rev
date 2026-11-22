// func mac_auth_print_group_entry @ 004577bc size=224

void mac_auth_print_group_entry(int param_1)

{
  char *pcVar1;
  
  if ((param_1 != 0) && (macauth_debug_switch != 0)) {
    puts("#####################################################################");
    printf("id\t\t\t\t= %d\n",*(undefined4 *)(param_1 + 0xc));
    printf("status\t\t\t= %d\n",*(undefined4 *)(param_1 + 0x10));
    printf("name\t\t\t= %s\n",param_1 + 0x14);
    printf("bind vlan\t\t= %s\n",param_1 + 0x14c);
    printf("bind map        = %08X\n",**(undefined4 **)(param_1 + 0x180));
    printf("note \t\t\t= %s\n",param_1 + 0xb0);
    if (*(int *)(param_1 + 0x184) == 0) {
      pcVar1 = "white_list";
    }
    else {
      pcVar1 = "black_list";
    }
    printf("type\t\t\t= %d %s\n",*(int *)(param_1 + 0x184),pcVar1);
    puts("\n#####################################################################");
    return;
  }
  return;
}

