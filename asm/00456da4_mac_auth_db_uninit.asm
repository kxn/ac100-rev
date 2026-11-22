; func mac_auth_db_uninit @ 0x00456da4 size=0x148
  456da4:	27bdffd8 	addiu	sp,sp,-40
  456da8:	afb10020 	sw	s1,32(sp)
  456dac:	3c110076 	lui	s1,0x76
  456db0:	afb0001c 	sw	s0,28(sp)
  456db4:	26306ff0 	addiu	s0,s1,28656
  456db8:	afbf0024 	sw	ra,36(sp)
  456dbc:	8e040004 	lw	a0,4(s0)
  456dc0:	50800006 	beqzl	a0,0x456ddc
  456dc4:	8e040008 	lw	a0,8(s0)
  456dc8:	0c1020d8 	jal	0x408360
  456dcc:	00000000 	nop
  456dd0:	ae000004 	sw	zero,4(s0)
  456dd4:	26306ff0 	addiu	s0,s1,28656
  456dd8:	8e040008 	lw	a0,8(s0)
  456ddc:	50800005 	beqzl	a0,0x456df4
  456de0:	26306ff0 	addiu	s0,s1,28656
  456de4:	0c1020d8 	jal	0x408360
  456de8:	00000000 	nop
  456dec:	ae000008 	sw	zero,8(s0)
  456df0:	26306ff0 	addiu	s0,s1,28656
  456df4:	8e04000c 	lw	a0,12(s0)
  456df8:	50800005 	beqzl	a0,0x456e10
  456dfc:	26306ff0 	addiu	s0,s1,28656
  456e00:	0c102058 	jal	0x408160
  456e04:	00000000 	nop
  456e08:	ae00000c 	sw	zero,12(s0)
  456e0c:	26306ff0 	addiu	s0,s1,28656
  456e10:	8e040010 	lw	a0,16(s0)
  456e14:	50800005 	beqzl	a0,0x456e2c
  456e18:	26306ff0 	addiu	s0,s1,28656
  456e1c:	0c102058 	jal	0x408160
  456e20:	00000000 	nop
  456e24:	ae000010 	sw	zero,16(s0)
  456e28:	26306ff0 	addiu	s0,s1,28656
  456e2c:	8e040014 	lw	a0,20(s0)
  456e30:	50800005 	beqzl	a0,0x456e48
  456e34:	26306ff0 	addiu	s0,s1,28656
  456e38:	0c102058 	jal	0x408160
  456e3c:	00000000 	nop
  456e40:	ae000014 	sw	zero,20(s0)
  456e44:	26306ff0 	addiu	s0,s1,28656
  456e48:	8e040030 	lw	a0,48(s0)
  456e4c:	50800005 	beqzl	a0,0x456e64
  456e50:	26306ff0 	addiu	s0,s1,28656
  456e54:	0c101f7c 	jal	0x407df0
  456e58:	00000000 	nop
  456e5c:	ae000030 	sw	zero,48(s0)
  456e60:	26306ff0 	addiu	s0,s1,28656
  456e64:	8e040034 	lw	a0,52(s0)
  456e68:	50800005 	beqzl	a0,0x456e80
  456e6c:	26306ff0 	addiu	s0,s1,28656
  456e70:	0c101f7c 	jal	0x407df0
  456e74:	00000000 	nop
  456e78:	ae000034 	sw	zero,52(s0)
  456e7c:	26306ff0 	addiu	s0,s1,28656
  456e80:	8e040018 	lw	a0,24(s0)
  456e84:	50800005 	beqzl	a0,0x456e9c
  456e88:	26306ff0 	addiu	s0,s1,28656
  456e8c:	0c1020c4 	jal	0x408310
  456e90:	00000000 	nop
  456e94:	ae000018 	sw	zero,24(s0)
  456e98:	26306ff0 	addiu	s0,s1,28656
  456e9c:	8e040028 	lw	a0,40(s0)
  456ea0:	50800005 	beqzl	a0,0x456eb8
  456ea4:	26306ff0 	addiu	s0,s1,28656
  456ea8:	0c101f7c 	jal	0x407df0
  456eac:	00000000 	nop
  456eb0:	ae000028 	sw	zero,40(s0)
  456eb4:	26306ff0 	addiu	s0,s1,28656
  456eb8:	8e04002c 	lw	a0,44(s0)
  456ebc:	10800005 	beqz	a0,0x456ed4
  456ec0:	8fbf0024 	lw	ra,36(sp)
  456ec4:	0c101f7c 	jal	0x407df0
  456ec8:	00000000 	nop
  456ecc:	ae00002c 	sw	zero,44(s0)
  456ed0:	8fbf0024 	lw	ra,36(sp)
  456ed4:	00001021 	move	v0,zero
  456ed8:	8fb0001c 	lw	s0,28(sp)
  456edc:	ae206ff0 	sw	zero,28656(s1)
  456ee0:	8fb10020 	lw	s1,32(sp)
  456ee4:	03e00008 	jr	ra
  456ee8:	27bd0028 	addiu	sp,sp,40
