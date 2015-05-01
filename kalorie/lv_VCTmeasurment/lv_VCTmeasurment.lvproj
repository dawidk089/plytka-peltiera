<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="12008004">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="ax+b(double).vi" Type="VI" URL="../ax+b(double).vi"/>
		<Item Name="ax+b.vi" Type="VI" URL="../ax+b.vi"/>
		<Item Name="bt.vi" Type="VI" URL="../bt.vi"/>
		<Item Name="meas_date.vi" Type="VI" URL="../meas_date.vi"/>
		<Item Name="uC_support.vi" Type="VI" URL="../uC_support.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Bluetooth Generate Error Cluster.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/Bluetooth.llb/Bluetooth Generate Error Cluster.vi"/>
				<Item Name="Bluetooth RFCOMM Service Discovery.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/Bluetooth.llb/Bluetooth RFCOMM Service Discovery.vi"/>
			</Item>
			<Item Name="bt_start_sub.vi" Type="VI" URL="../bt_start_sub.vi"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
