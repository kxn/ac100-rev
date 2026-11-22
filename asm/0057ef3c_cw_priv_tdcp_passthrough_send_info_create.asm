; func cw_priv_tdcp_passthrough_send_info_create @ 0x0057ef3c size=0x1d4
  57ef3c:	27bdffd8 	addiu	sp,sp,-40
  57ef40:	24050010 	li	a1,16
  57ef44:	afb10020 	sw	s1,32(sp)
  57ef48:	afb0001c 	sw	s0,28(sp)
  57ef4c:	afbf0024 	sw	ra,36(sp)
  57ef50:	0c15c8cc 	jal	0x572330
  57ef54:	00808821 	move	s1,a0
  57ef58:	10400031 	beqz	v0,0x57f020
  57ef5c:	00408021 	move	s0,v0
  57ef60:	ac40000c 	sw	zero,12(v0)
  57ef64:	ac400004 	sw	zero,4(v0)
  57ef68:	ac400000 	sw	zero,0(v0)
  57ef6c:	a0400008 	sb	zero,8(v0)
  57ef70:	8e250004 	lw	a1,4(s1)
  57ef74:	10a00011 	beqz	a1,0x57efbc
  57ef78:	24040083 	li	a0,131
  57ef7c:	8e24000c 	lw	a0,12(s1)
  57ef80:	10800043 	beqz	a0,0x57f090
  57ef84:	3c020075 	lui	v0,0x75
  57ef88:	24a50001 	addiu	a1,a1,1
  57ef8c:	0c15c8cc 	jal	0x572330
  57ef90:	30a5ffff 	andi	a1,a1,0xffff
  57ef94:	10400045 	beqz	v0,0x57f0ac
  57ef98:	ae02000c 	sw	v0,12(s0)
  57ef9c:	8e220004 	lw	v0,4(s1)
  57efa0:	ae020004 	sw	v0,4(s0)
  57efa4:	8e220000 	lw	v0,0(s1)
  57efa8:	ae020000 	sw	v0,0(s0)
  57efac:	92220008 	lbu	v0,8(s1)
  57efb0:	a2020008 	sb	v0,8(s0)
  57efb4:	8e250004 	lw	a1,4(s1)
  57efb8:	24040083 	li	a0,131
  57efbc:	02003021 	move	a2,s0
  57efc0:	24a50009 	addiu	a1,a1,9
  57efc4:	0c15c943 	jal	0x57250c
  57efc8:	30a5ffff 	andi	a1,a1,0xffff
  57efcc:	10400007 	beqz	v0,0x57efec
  57efd0:	00408821 	move	s1,v0
  57efd4:	8fbf0024 	lw	ra,36(sp)
  57efd8:	02201021 	move	v0,s1
  57efdc:	8fb10020 	lw	s1,32(sp)
  57efe0:	8fb0001c 	lw	s0,28(sp)
  57efe4:	03e00008 	jr	ra
  57efe8:	27bd0028 	addiu	sp,sp,40
  57efec:	3c020075 	lui	v0,0x75
  57eff0:	8c42cf58 	lw	v0,-12456(v0)
  57eff4:	1440001a 	bnez	v0,0x57f060
  57eff8:	00000000 	nop
  57effc:	8e04000c 	lw	a0,12(s0)
  57f000:	10800003 	beqz	a0,0x57f010
  57f004:	00000000 	nop
  57f008:	0c101f7c 	jal	0x407df0
  57f00c:	00000000 	nop
  57f010:	0c101f7c 	jal	0x407df0
  57f014:	02002021 	move	a0,s0
  57f018:	0815fbf6 	j	0x57efd8
  57f01c:	8fbf0024 	lw	ra,36(sp)
  57f020:	3c020075 	lui	v0,0x75
  57f024:	8c42cf58 	lw	v0,-12456(v0)
  57f028:	1040ffea 	beqz	v0,0x57efd4
  57f02c:	00008821 	move	s1,zero
  57f030:	0c16276a 	jal	0x589da8
  57f034:	00000000 	nop
  57f038:	5040ffe7 	beqzl	v0,0x57efd8
  57f03c:	8fbf0024 	lw	ra,36(sp)
  57f040:	3c04006d 	lui	a0,0x6d
  57f044:	3c05006e 	lui	a1,0x6e
  57f048:	248434fc 	addiu	a0,a0,13564
  57f04c:	24a5af20 	addiu	a1,a1,-20704
  57f050:	0c101b74 	jal	0x406dd0
  57f054:	240600c1 	li	a2,193
  57f058:	0815fbf6 	j	0x57efd8
  57f05c:	8fbf0024 	lw	ra,36(sp)
  57f060:	0c16276a 	jal	0x589da8
  57f064:	00000000 	nop
  57f068:	5040ffe5 	beqzl	v0,0x57f000
  57f06c:	8e04000c 	lw	a0,12(s0)
  57f070:	3c04006d 	lui	a0,0x6d
  57f074:	3c05006e 	lui	a1,0x6e
  57f078:	248447f0 	addiu	a0,a0,18416
  57f07c:	24a5af20 	addiu	a1,a1,-20704
  57f080:	0c101b74 	jal	0x406dd0
  57f084:	240600e0 	li	a2,224
  57f088:	0815fc00 	j	0x57f000
  57f08c:	8e04000c 	lw	a0,12(s0)
  57f090:	8c42cf58 	lw	v0,-12456(v0)
  57f094:	14400015 	bnez	v0,0x57f0ec
  57f098:	00000000 	nop
  57f09c:	0c101f7c 	jal	0x407df0
  57f0a0:	02002021 	move	a0,s0
  57f0a4:	0815fbf5 	j	0x57efd4
  57f0a8:	00008821 	move	s1,zero
  57f0ac:	3c020075 	lui	v0,0x75
  57f0b0:	8c42cf58 	lw	v0,-12456(v0)
  57f0b4:	1040fff9 	beqz	v0,0x57f09c
  57f0b8:	00000000 	nop
  57f0bc:	0c16276a 	jal	0x589da8
  57f0c0:	00000000 	nop
  57f0c4:	1040fff5 	beqz	v0,0x57f09c
  57f0c8:	3c04006e 	lui	a0,0x6e
  57f0cc:	3c05006e 	lui	a1,0x6e
  57f0d0:	24848050 	addiu	a0,a0,-32688
  57f0d4:	24a5af20 	addiu	a1,a1,-20704
  57f0d8:	240600d4 	li	a2,212
  57f0dc:	0c101b74 	jal	0x406dd0
  57f0e0:	00000000 	nop
  57f0e4:	0815fc27 	j	0x57f09c
  57f0e8:	00000000 	nop
  57f0ec:	0c16276a 	jal	0x589da8
  57f0f0:	00000000 	nop
  57f0f4:	1040ffe9 	beqz	v0,0x57f09c
  57f0f8:	3c04006e 	lui	a0,0x6e
  57f0fc:	3c05006e 	lui	a1,0x6e
  57f100:	248480d8 	addiu	a0,a0,-32552
  57f104:	24a5af20 	addiu	a1,a1,-20704
  57f108:	0815fc37 	j	0x57f0dc
  57f10c:	240600cd 	li	a2,205
