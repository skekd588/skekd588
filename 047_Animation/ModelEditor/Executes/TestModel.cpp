#include "stdafx.h"
#include "TestModel.h"
#include "Fbx/FbxLoader.h"

void TestModel::Initialize()
{
	FbxLoader* loader = NULL;

	loader = new FbxLoader
	(
		Assets + L"Tank/Tank.fbx", Models + L"Tank/", L"Tank"
	);
	loader->ExportMaterial();
	loader->ExportMesh();
	SAFE_DELETE(loader);
}

void TestModel::Ready() // 데이터가 복사되는것은 이쪽으로
{
	model = new GameModel
	(
		Shaders + L"046_Model.fx",
		Models + L"Tank/Tank.material",
		Models + L"Tank/Tank.mesh"
	);
	model->Ready();
}

void TestModel::Destroy()
{
	
}

void TestModel::Update()
{
	model->Update();
}

void TestModel::PreRender()
{

}

void TestModel::Render()
{
	model->Render();
}