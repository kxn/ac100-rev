// func jcs_test_callback_add @ 00527370 size=4592

void jcs_test_callback_add(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  undefined8 *puVar11;
  undefined1 *puVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  int in_t9;
  undefined8 uVar16;
  uint local_350;
  undefined4 local_34c;
  undefined1 auStack_348 [255];
  undefined1 local_249;
  undefined4 local_240 [4];
  uint local_230 [4];
  undefined8 local_220;
  undefined1 auStack_1f8 [384];
  undefined4 local_78;
  undefined1 auStack_74 [63];
  undefined1 local_35;
  undefined4 local_34 [3];
  
  (**(code **)(in_t9 + 0x232438))(&local_350,0,0x328);
  iVar1 = (**(code **)(in_t9 + 0x2322d4))(param_1,*(int *)(in_t9 + 0x231db0) + -0x4730);
  if (iVar1 == 0) {
LAB_00527420:
    if (**(int **)(in_t9 + 0x231e80) != 0) {
      (**(code **)(in_t9 + 0x232560))
                (*(int *)(in_t9 + 0x231db0) + 0x47c8,*(int *)(in_t9 + 0x231db8) + 0x5418,0x209);
    }
    local_350 = 0;
  }
  else {
    iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1);
    if (iVar2 == 1) {
      local_350 = (**(code **)(in_t9 + 0x2323d8))(iVar1);
    }
    else {
      iVar2 = (**(code **)(in_t9 + 0x2324f8))();
      if (iVar2 != 3) goto LAB_00527420;
      iVar1 = (**(code **)(in_t9 + 0x232424))(iVar1);
      local_350 = (uint)(iVar1 != 0);
    }
  }
  if (**(int **)(in_t9 + 0x23219c) != 0) {
    (**(code **)(in_t9 + 0x232560))
              (*(int *)(in_t9 + 0x231db8) + 0x4950,*(int *)(in_t9 + 0x231db8) + 0x5418,0x20a,
               local_350);
  }
  iVar1 = (**(code **)(in_t9 + 0x2322d4))(param_1,*(int *)(in_t9 + 0x231db8) + 0x4974);
  if (iVar1 == 0) {
LAB_00527498:
    if (**(int **)(in_t9 + 0x231e80) != 0) {
      (**(code **)(in_t9 + 0x232560))
                (*(int *)(in_t9 + 0x231da8) + 0x6a80,*(int *)(in_t9 + 0x231db8) + 0x5418,0x20f);
    }
    local_34c = 0xffffffff;
  }
  else {
    iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1);
    if (iVar2 == 3) {
      local_34c = (**(code **)(in_t9 + 0x232424))(iVar1);
    }
    else {
      iVar2 = (**(code **)(in_t9 + 0x2324f8))();
      if (iVar2 != 2) goto LAB_00527498;
      uVar16 = (**(code **)(in_t9 + 0x2324b0))(iVar1);
      local_34c = (**(code **)(in_t9 + 0x23228c))((int)((ulonglong)uVar16 >> 0x20),(int)uVar16);
    }
  }
  if (**(int **)(in_t9 + 0x23219c) != 0) {
    (**(code **)(in_t9 + 0x232560))
              (*(int *)(in_t9 + 0x231db8) + 0x4980,*(int *)(in_t9 + 0x231db8) + 0x5418,0x210,
               local_34c);
  }
  iVar1 = (**(code **)(in_t9 + 0x2322d4))(param_1,*(int *)(in_t9 + 0x231da8) + 0x7ca8);
  if ((iVar1 == 0) || (iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1), iVar2 != 6)) {
    if (**(int **)(in_t9 + 0x231e80) != 0) {
      (**(code **)(in_t9 + 0x232560))
                (*(int *)(in_t9 + 0x231da8) + 0x69bc,*(int *)(in_t9 + 0x231db8) + 0x5418,0x214);
    }
    iVar1 = *(int *)(in_t9 + 0x231e50) + -0x7508;
  }
  else {
    iVar1 = (**(code **)(in_t9 + 0x2324a0))(iVar1);
  }
  (**(code **)(in_t9 + 0x23231c))(auStack_348,iVar1,0xff);
  local_249 = 0;
  if (**(int **)(in_t9 + 0x23219c) != 0) {
    (**(code **)(in_t9 + 0x232560))
              (*(int *)(in_t9 + 0x231db8) + 0x49a4,*(int *)(in_t9 + 0x231db8) + 0x5418,0x215,
               auStack_348);
  }
  iVar1 = (**(code **)(in_t9 + 0x2322d4))(param_1,*(int *)(in_t9 + 0x231db8) + 0x49c4);
  if (iVar1 == 0) {
LAB_00527588:
    piVar3 = *(int **)(in_t9 + 0x231e80);
LAB_0052758c:
    iVar2 = 0;
    if (*piVar3 != 0) {
      (**(code **)(in_t9 + 0x232560))
                (*(int *)(in_t9 + 0x231da8) + 0x75ec,*(int *)(in_t9 + 0x231db8) + 0x5418,0x219);
    }
  }
  else {
    iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1);
    if (iVar2 != 5) {
      iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1);
      if (iVar2 != 4) goto LAB_00527588;
      iVar2 = 0;
      iVar1 = (**(code **)(in_t9 + 0x232488))(iVar1);
      if (iVar1 == 0) goto LAB_00527598;
      piVar3 = *(int **)(in_t9 + 0x231e80);
      goto LAB_0052758c;
    }
    iVar14 = *(int *)(in_t9 + 0x231da8);
    puVar13 = local_240;
    iVar15 = *(int *)(in_t9 + 0x231db8);
    piVar3 = *(int **)(in_t9 + 0x231e80);
    for (iVar2 = 0; iVar6 = (**(code **)(in_t9 + 0x232510))(iVar1), iVar2 < iVar6; iVar2 = iVar2 + 1
        ) {
      if (iVar2 == 4) {
        iVar2 = 4;
        break;
      }
      iVar6 = (**(code **)(in_t9 + 0x232498))(iVar1,iVar2);
      if (iVar6 == 0) {
LAB_00528170:
        if (*piVar3 != 0) {
          (**(code **)(in_t9 + 0x232560))(iVar14 + 0x6a80,iVar15 + 0x5418,0x219);
        }
        uVar4 = 0xffffffff;
      }
      else {
        iVar7 = (**(code **)(in_t9 + 0x2324f8))(iVar6);
        if (iVar7 == 3) {
          uVar4 = (**(code **)(in_t9 + 0x232424))(iVar6);
        }
        else {
          iVar7 = (**(code **)(in_t9 + 0x2324f8))();
          if (iVar7 != 2) goto LAB_00528170;
          uVar16 = (**(code **)(in_t9 + 0x2324b0))(iVar6);
          uVar4 = (**(code **)(in_t9 + 0x23228c))((int)((ulonglong)uVar16 >> 0x20),(int)uVar16);
        }
      }
      *puVar13 = uVar4;
      puVar13 = puVar13 + 1;
    }
  }
LAB_00527598:
  iVar14 = *(int *)(in_t9 + 0x231db8);
  puVar13 = local_240;
  iVar15 = *(int *)(in_t9 + 0x231db8);
  iVar1 = 0;
  piVar3 = *(int **)(in_t9 + 0x23219c);
  while (iVar1 < iVar2) {
    if (*piVar3 == 0) {
      iVar1 = iVar1 + 1;
      puVar13 = puVar13 + 1;
    }
    else {
      (**(code **)(in_t9 + 0x232560))(iVar14 + 0x49cc,iVar15 + 0x5418,0x21c,iVar1,*puVar13);
      iVar1 = iVar1 + 1;
      puVar13 = puVar13 + 1;
    }
  }
  iVar1 = (**(code **)(in_t9 + 0x2322d4))(param_1,*(int *)(in_t9 + 0x231db8) + 0x49f4);
  if (iVar1 == 0) {
LAB_00527650:
    piVar3 = *(int **)(in_t9 + 0x231e80);
LAB_00527654:
    iVar2 = 0;
    if (*piVar3 != 0) {
      (**(code **)(in_t9 + 0x232560))
                (*(int *)(in_t9 + 0x231db8) + 0x49fc,*(int *)(in_t9 + 0x231db8) + 0x5418,0x221);
    }
  }
  else {
    iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1);
    if (iVar2 != 5) {
      iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1);
      if (iVar2 != 4) goto LAB_00527650;
      iVar2 = 0;
      iVar1 = (**(code **)(in_t9 + 0x232488))(iVar1);
      if (iVar1 == 0) goto LAB_00527660;
      piVar3 = *(int **)(in_t9 + 0x231e80);
      goto LAB_00527654;
    }
    iVar14 = *(int *)(in_t9 + 0x231db0);
    puVar10 = local_230;
    iVar15 = *(int *)(in_t9 + 0x231db8);
    iVar2 = 0;
    piVar3 = *(int **)(in_t9 + 0x231e80);
    while (iVar6 = (**(code **)(in_t9 + 0x232510))(iVar1), iVar2 < iVar6) {
      if (iVar2 == 4) {
        iVar2 = 4;
        break;
      }
      iVar6 = (**(code **)(in_t9 + 0x232498))(iVar1,iVar2);
      if (iVar6 == 0) {
LAB_005280ac:
        if (*piVar3 == 0) {
          *puVar10 = 0;
        }
        else {
          (**(code **)(in_t9 + 0x232560))(iVar14 + 0x47c8,iVar15 + 0x5418,0x221);
          *puVar10 = 0;
        }
        iVar2 = iVar2 + 1;
        puVar10 = puVar10 + 1;
      }
      else {
        iVar7 = (**(code **)(in_t9 + 0x2324f8))(iVar6);
        if (iVar7 == 1) {
          uVar9 = (**(code **)(in_t9 + 0x2323d8))(iVar6);
          *puVar10 = uVar9;
        }
        else {
          iVar7 = (**(code **)(in_t9 + 0x2324f8))();
          if (iVar7 != 3) goto LAB_005280ac;
          iVar6 = (**(code **)(in_t9 + 0x232424))(iVar6);
          *puVar10 = (uint)(iVar6 != 0);
        }
        iVar2 = iVar2 + 1;
        puVar10 = puVar10 + 1;
      }
    }
  }
LAB_00527660:
  iVar14 = *(int *)(in_t9 + 0x231db8);
  puVar10 = local_230;
  iVar15 = *(int *)(in_t9 + 0x231db8);
  iVar1 = 0;
  piVar3 = *(int **)(in_t9 + 0x23219c);
  while (iVar1 < iVar2) {
    if (*piVar3 == 0) {
      iVar1 = iVar1 + 1;
      puVar10 = puVar10 + 1;
    }
    else {
      (**(code **)(in_t9 + 0x232560))(iVar14 + 0x4a54,iVar15 + 0x5418,0x224,iVar1,*puVar10);
      iVar1 = iVar1 + 1;
      puVar10 = puVar10 + 1;
    }
  }
  iVar1 = (**(code **)(in_t9 + 0x2322d4))(param_1,*(int *)(in_t9 + 0x231db8) + 0x4a7c);
  if (iVar1 == 0) {
LAB_00527718:
    piVar3 = *(int **)(in_t9 + 0x231e80);
LAB_0052771c:
    iVar2 = 0;
    if (*piVar3 != 0) {
      (**(code **)(in_t9 + 0x232560))
                (*(int *)(in_t9 + 0x231db8) + 0x4ad4,*(int *)(in_t9 + 0x231db8) + 0x5418,0x229);
    }
  }
  else {
    iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1);
    if (iVar2 != 5) {
      iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1);
      if (iVar2 != 4) goto LAB_00527718;
      iVar2 = 0;
      iVar1 = (**(code **)(in_t9 + 0x232488))(iVar1);
      if (iVar1 == 0) goto LAB_00527728;
      piVar3 = *(int **)(in_t9 + 0x231e80);
      goto LAB_0052771c;
    }
    iVar14 = *(int *)(in_t9 + 0x231db8);
    puVar11 = &local_220;
    iVar15 = *(int *)(in_t9 + 0x231db8);
    iVar2 = 0;
    piVar3 = *(int **)(in_t9 + 0x231e80);
    while (iVar6 = (**(code **)(in_t9 + 0x232510))(iVar1), iVar2 < iVar6) {
      if (iVar2 == 5) {
        iVar2 = 5;
        break;
      }
      iVar6 = (**(code **)(in_t9 + 0x232498))(iVar1,iVar2);
      if (iVar6 == 0) {
LAB_005282f4:
        if (*piVar3 == 0) {
          *(undefined4 *)((int)puVar11 + 4) = 0;
          *(undefined4 *)puVar11 = 0;
        }
        else {
          (**(code **)(in_t9 + 0x232560))(iVar14 + 0x4a84,iVar15 + 0x5418,0x229);
          *(undefined4 *)((int)puVar11 + 4) = 0;
          *(undefined4 *)puVar11 = 0;
        }
        iVar2 = iVar2 + 1;
        puVar11 = puVar11 + 1;
      }
      else {
        iVar7 = (**(code **)(in_t9 + 0x2324f8))(iVar6);
        if (iVar7 == 2) {
          uVar16 = (**(code **)(in_t9 + 0x2324b0))(iVar6);
          *puVar11 = uVar16;
        }
        else {
          iVar7 = (**(code **)(in_t9 + 0x2324f8))();
          if (iVar7 != 3) goto LAB_005282f4;
          uVar4 = (**(code **)(in_t9 + 0x232424))(iVar6);
          uVar16 = (**(code **)(in_t9 + 0x23235c))(uVar4);
          *puVar11 = uVar16;
        }
        iVar2 = iVar2 + 1;
        puVar11 = puVar11 + 1;
      }
    }
  }
LAB_00527728:
  iVar14 = *(int *)(in_t9 + 0x231db8);
  puVar11 = &local_220;
  iVar15 = *(int *)(in_t9 + 0x231db8);
  piVar3 = *(int **)(in_t9 + 0x23219c);
  iVar1 = 0;
  while (iVar1 < iVar2) {
    if (*piVar3 == 0) {
      iVar1 = iVar1 + 1;
      puVar11 = puVar11 + 1;
    }
    else {
      (**(code **)(in_t9 + 0x232560))
                (iVar14 + 0x4b28,iVar15 + 0x5418,0x22c,iVar1,*(undefined4 *)puVar11,
                 *(undefined4 *)((int)puVar11 + 4));
      puVar11 = puVar11 + 1;
      iVar1 = iVar1 + 1;
    }
  }
  iVar1 = (**(code **)(in_t9 + 0x2322d4))(param_1,*(int *)(in_t9 + 0x231db8) + 0x4b50);
  if (iVar1 == 0) {
LAB_005277e8:
    piVar3 = *(int **)(in_t9 + 0x231e80);
LAB_005277ec:
    iVar2 = 0;
    if (*piVar3 != 0) {
      (**(code **)(in_t9 + 0x232560))
                (*(int *)(in_t9 + 0x231db0) + -0x768c,*(int *)(in_t9 + 0x231db8) + 0x5418,0x231);
    }
  }
  else {
    iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1);
    if (iVar2 != 5) {
      iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1);
      if (iVar2 != 4) goto LAB_005277e8;
      iVar2 = 0;
      iVar1 = (**(code **)(in_t9 + 0x232488))(iVar1);
      if (iVar1 == 0) goto LAB_005277f8;
      piVar3 = *(int **)(in_t9 + 0x231e80);
      goto LAB_005277ec;
    }
    puVar12 = auStack_1f8;
    iVar15 = *(int *)(in_t9 + 0x231da8);
    iVar6 = *(int *)(in_t9 + 0x231db8);
    iVar14 = *(int *)(in_t9 + 0x231e50) + -0x7508;
    for (iVar2 = 0; iVar7 = (**(code **)(in_t9 + 0x232510))(iVar1), iVar2 < iVar7; iVar2 = iVar2 + 1
        ) {
      if (iVar2 == 3) {
        iVar2 = 3;
        break;
      }
      iVar7 = (**(code **)(in_t9 + 0x232498))(iVar1,iVar2);
      if ((iVar7 == 0) || (iVar8 = (**(code **)(in_t9 + 0x2324f8))(iVar7), iVar8 != 6)) {
        iVar7 = iVar14;
        if (**(int **)(in_t9 + 0x231e80) != 0) {
          (**(code **)(in_t9 + 0x232560))(iVar15 + 0x69bc,iVar6 + 0x5418,0x231);
        }
      }
      else {
        iVar7 = (**(code **)(in_t9 + 0x2324a0))(iVar7);
      }
      (**(code **)(in_t9 + 0x23231c))(puVar12,iVar7,0x7f);
      puVar12[0x7f] = 0;
      puVar12 = puVar12 + 0x80;
    }
  }
LAB_005277f8:
  iVar14 = *(int *)(in_t9 + 0x231db8);
  puVar12 = auStack_1f8;
  iVar15 = *(int *)(in_t9 + 0x231db8);
  iVar1 = 0;
  piVar3 = *(int **)(in_t9 + 0x23219c);
  while (iVar1 < iVar2) {
    if (*piVar3 == 0) {
      iVar1 = iVar1 + 1;
      puVar12 = puVar12 + 0x80;
    }
    else {
      (**(code **)(in_t9 + 0x232560))(iVar14 + 0x4b58,iVar15 + 0x5418,0x234,iVar1,puVar12);
      iVar1 = iVar1 + 1;
      puVar12 = puVar12 + 0x80;
    }
  }
  uVar4 = (**(code **)(in_t9 + 0x2322d4))(param_1,*(int *)(in_t9 + 0x231db8) + 0x4b80);
  iVar1 = (**(code **)(in_t9 + 0x2322d4))(uVar4,*(int *)(in_t9 + 0x231db8) + 0x4b84);
  if (iVar1 == 0) {
LAB_005278cc:
    if (**(int **)(in_t9 + 0x231e80) != 0) {
      (**(code **)(in_t9 + 0x232560))
                (*(int *)(in_t9 + 0x231da8) + 0x6a80,*(int *)(in_t9 + 0x231db8) + 0x5418,0x23c);
    }
    local_78 = 0xffffffff;
  }
  else {
    iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1);
    if (iVar2 == 3) {
      local_78 = (**(code **)(in_t9 + 0x232424))(iVar1);
    }
    else {
      iVar2 = (**(code **)(in_t9 + 0x2324f8))();
      if (iVar2 != 2) goto LAB_005278cc;
      uVar16 = (**(code **)(in_t9 + 0x2324b0))(iVar1);
      local_78 = (**(code **)(in_t9 + 0x23228c))((int)((ulonglong)uVar16 >> 0x20),(int)uVar16);
    }
  }
  if (**(int **)(in_t9 + 0x23219c) != 0) {
    (**(code **)(in_t9 + 0x232560))
              (*(int *)(in_t9 + 0x231db8) + 0x4b88,*(int *)(in_t9 + 0x231db8) + 0x5418,0x23d,
               local_78);
  }
  iVar1 = (**(code **)(in_t9 + 0x2322d4))(uVar4,*(int *)(in_t9 + 0x231db8) + 0x4bac);
  if ((iVar1 == 0) || (iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1), iVar2 != 6)) {
    if (**(int **)(in_t9 + 0x231e80) != 0) {
      (**(code **)(in_t9 + 0x232560))
                (*(int *)(in_t9 + 0x231da8) + 0x69bc,*(int *)(in_t9 + 0x231db8) + 0x5418,0x240);
    }
    iVar1 = *(int *)(in_t9 + 0x231e50) + -0x7508;
  }
  else {
    iVar1 = (**(code **)(in_t9 + 0x2324a0))(iVar1);
  }
  (**(code **)(in_t9 + 0x23231c))(auStack_74,iVar1,0x3f);
  local_35 = 0;
  if (**(int **)(in_t9 + 0x23219c) != 0) {
    (**(code **)(in_t9 + 0x232560))
              (*(int *)(in_t9 + 0x231db8) + 0x4bb0,*(int *)(in_t9 + 0x231db8) + 0x5418,0x241,
               auStack_74);
  }
  iVar1 = (**(code **)(in_t9 + 0x2322d4))(uVar4,*(int *)(in_t9 + 0x231db8) + 0x4bd4);
  if (iVar1 == 0) {
LAB_005279bc:
    piVar3 = *(int **)(in_t9 + 0x231e80);
  }
  else {
    iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1);
    if (iVar2 == 5) {
      iVar14 = *(int *)(in_t9 + 0x231da8);
      puVar13 = local_34;
      iVar15 = *(int *)(in_t9 + 0x231db8);
      piVar3 = *(int **)(in_t9 + 0x231e80);
      for (iVar2 = 0; iVar6 = (**(code **)(in_t9 + 0x232510))(iVar1), iVar2 < iVar6;
          iVar2 = iVar2 + 1) {
        if (iVar2 == 3) {
          iVar2 = 3;
          break;
        }
        iVar6 = (**(code **)(in_t9 + 0x232498))(iVar1,iVar2);
        if (iVar6 == 0) {
LAB_00527fe8:
          if (*piVar3 != 0) {
            (**(code **)(in_t9 + 0x232560))(iVar14 + 0x6a80,iVar15 + 0x5418,0x244);
          }
          uVar4 = 0xffffffff;
        }
        else {
          iVar7 = (**(code **)(in_t9 + 0x2324f8))(iVar6);
          if (iVar7 == 3) {
            uVar4 = (**(code **)(in_t9 + 0x232424))(iVar6);
          }
          else {
            iVar7 = (**(code **)(in_t9 + 0x2324f8))();
            if (iVar7 != 2) goto LAB_00527fe8;
            uVar16 = (**(code **)(in_t9 + 0x2324b0))(iVar6);
            uVar4 = (**(code **)(in_t9 + 0x23228c))((int)((ulonglong)uVar16 >> 0x20),(int)uVar16);
          }
        }
        *puVar13 = uVar4;
        puVar13 = puVar13 + 1;
      }
      goto LAB_005279cc;
    }
    iVar2 = (**(code **)(in_t9 + 0x2324f8))(iVar1);
    if (iVar2 != 4) goto LAB_005279bc;
    iVar2 = 0;
    iVar1 = (**(code **)(in_t9 + 0x232488))(iVar1);
    if (iVar1 == 0) goto LAB_005279cc;
    piVar3 = *(int **)(in_t9 + 0x231e80);
  }
  iVar2 = 0;
  if (*piVar3 != 0) {
    (**(code **)(in_t9 + 0x232560))
              (*(int *)(in_t9 + 0x231da8) + 0x75ec,*(int *)(in_t9 + 0x231db8) + 0x5418,0x244);
  }
LAB_005279cc:
  iVar14 = *(int *)(in_t9 + 0x231db8);
  puVar13 = local_34;
  iVar15 = *(int *)(in_t9 + 0x231db8);
  iVar1 = 0;
  piVar3 = *(int **)(in_t9 + 0x23219c);
  while (iVar1 < iVar2) {
    if (*piVar3 == 0) {
      iVar1 = iVar1 + 1;
      puVar13 = puVar13 + 1;
    }
    else {
      (**(code **)(in_t9 + 0x232560))(iVar14 + 0x4be0,iVar15 + 0x5418,0x247,iVar1,*puVar13);
      iVar1 = iVar1 + 1;
      puVar13 = puVar13 + 1;
    }
  }
  uVar4 = (**(code **)(in_t9 + 0x232274))(1);
  (**(code **)(in_t9 + 0x2323c8))(param_2,*(int *)(in_t9 + 0x231da8) + 0x6a24,uVar4);
  uVar4 = (**(code **)(in_t9 + 0x232344))
                    (*(undefined4 *)(*(int *)(in_t9 + 0x231db8) + 0x5450),
                     *(undefined4 *)(*(int *)(in_t9 + 0x231db8) + 0x5454));
  (**(code **)(in_t9 + 0x2323c8))(param_2,*(int *)(in_t9 + 0x231db8) + 0x4c0c,uVar4);
  uVar4 = (**(code **)(in_t9 + 0x232408))(10);
  (**(code **)(in_t9 + 0x2323c8))(param_2,*(int *)(in_t9 + 0x231db8) + 0x4c14,uVar4);
  uVar4 = (**(code **)(in_t9 + 0x2324d4))(*(int *)(in_t9 + 0x231db8) + 0x4c18);
  (**(code **)(in_t9 + 0x2323c8))(param_2,*(int *)(in_t9 + 0x231e88) + 0x69b8,uVar4);
  uVar4 = (**(code **)(in_t9 + 0x2324e0))();
  uVar5 = (**(code **)(in_t9 + 0x232408))(2);
  (**(code **)(in_t9 + 0x232490))(uVar4,uVar5);
  uVar5 = (**(code **)(in_t9 + 0x232408))(3);
  (**(code **)(in_t9 + 0x232490))(uVar4,uVar5);
  uVar5 = (**(code **)(in_t9 + 0x232408))(4);
  (**(code **)(in_t9 + 0x232490))(uVar4,uVar5);
  (**(code **)(in_t9 + 0x2323c8))(param_2,*(int *)(in_t9 + 0x231e38) + 0x6e34,uVar4);
  uVar4 = (**(code **)(in_t9 + 0x23248c))();
  uVar5 = (**(code **)(in_t9 + 0x2324d4))(*(int *)(in_t9 + 0x231db8) + 0x4c24);
  (**(code **)(in_t9 + 0x2323c8))(uVar4,*(int *)(in_t9 + 0x231db8) + 0x4c2c,uVar5);
  uVar5 = (**(code **)(in_t9 + 0x232408))(0x85);
  (**(code **)(in_t9 + 0x2323c8))(uVar4,*(int *)(in_t9 + 0x231db8) + 0x4c34,uVar5);
  uVar5 = (**(code **)(in_t9 + 0x232408))(0x17);
  (**(code **)(in_t9 + 0x2323c8))(uVar4,*(int *)(in_t9 + 0x231db8) + 0x4c3c,uVar5);
  (**(code **)(in_t9 + 0x2323c8))(param_2,*(int *)(in_t9 + 0x231dac) + 0x1bac,uVar4);
  if (**(int **)(in_t9 + 0x23219c) != 0) {
    uVar4 = (**(code **)(in_t9 + 0x23242c))(param_2,0);
    (**(code **)(in_t9 + 0x232560))
              (*(int *)(in_t9 + 0x231db8) + 0x4c44,*(int *)(in_t9 + 0x231db8) + 0x5418,0x269,uVar4);
  }
  return;
}

