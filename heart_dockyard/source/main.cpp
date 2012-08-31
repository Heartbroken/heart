#include "header.hpp"

// OGRE
#include <Ogre.h>

#ifndef RENDER_API
#   define RENDER_API "Direct3D9" // "Direct3D9" // "GL"
#endif

#ifndef _DEBUG
#	pragma comment(lib, "OgreMain.lib")
#   define RENDER_SYSTEM "RenderSystem_"RENDER_API
#else
#	pragma comment(lib, "OgreMain_d.lib")
#   define RENDER_SYSTEM "RenderSystem_"RENDER_API"_d"
#endif

void test()
{
	Ogre::Root* pOgre = new Ogre::Root("", "");

    pOgre->loadPlugin(RENDER_SYSTEM);
	pOgre->setRenderSystem(pOgre->getAvailableRenderers().front());

	pOgre->initialise(false);
	
	Ogre::NameValuePairList lArgs;
	//lArgs["externalWindowHandle"] = bk::format("%d", (bk::uint)l_window.get_handle()).astr;
	Ogre::RenderWindow* pWindow = pOgre->createRenderWindow("Heart|Dockyard", 1024, 768, false, &lArgs);

	Ogre::SceneManager* pSceneManager = pOgre->createSceneManager(Ogre::ST_GENERIC,"SceneManager");
	pSceneManager->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
	pSceneManager->setShadowCameraSetup(Ogre::ShadowCameraSetupPtr(new Ogre::FocusedShadowCameraSetup()));
	pSceneManager->setAmbientLight(Ogre::ColourValue(0.1f, 0.1f, 0.1f));

	Ogre::Camera* pCamera = pSceneManager->createCamera("Camera");
	pCamera->setFixedYawAxis(true, Ogre::Vector3::UNIT_Z);
	pCamera->setPosition(Ogre::Vector3(0.0f, 50.0f, 20.0f)); 
	pCamera->lookAt(Ogre::Vector3(0.0f, 0.0f, 0.0f)); 
	pCamera->setNearClipDistance(0.1f); 
	pCamera->setFarClipDistance(100.0f);
	Ogre::Viewport* pViewport = pWindow->addViewport(pCamera);
	pViewport->setBackgroundColour(Ogre::ColourValue(0.0f, 0.0f, 0.0f));
	pCamera->setAspectRatio(Ogre::Real(pViewport->getActualWidth()) / Ogre::Real(pViewport->getActualHeight()));

	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../data/materials/scripts", "FileSystem", "Test");
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../data/materials/programs", "FileSystem", "Test");
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../data/materials/textures", "FileSystem", "Test");
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	Ogre::MeshManager::getSingleton().createPlane("GroundPlane", "Test", Ogre::Plane(0.0f, 0.0f, 1.0f, 0.0f), 100.0f, 100.0f, 100, 100, true, 1, 3.0f, 3.0f);
	Ogre::Entity* pGroundEntity = pSceneManager->createEntity("GroundPlane");
	pGroundEntity->setMaterialName("Examples/Rockwall");
	pGroundEntity->setCastShadows(false);
	pGroundEntity->getSubEntity(0)->getMaterial()->setShadingMode(Ogre::SO_PHONG);
	Ogre::SceneNode* pGroundNode = pSceneManager->getRootSceneNode()->createChildSceneNode();
	pGroundNode->attachObject(pGroundEntity);

	Ogre::Entity* pCubeEntity = pSceneManager->createEntity("Cube", Ogre::SceneManager::PT_CUBE);
	pCubeEntity->setMaterialName("Examples/10PointBlock");
	pCubeEntity->setCastShadows(true);
	Ogre::SceneNode* pCubeNode = pSceneManager->getRootSceneNode()->createChildSceneNode();
	pCubeNode->attachObject(pCubeEntity);
	pCubeNode->setPosition(0.0f, 0.0f, 5.f);
	pCubeNode->setScale(0.1f, 0.1f, 0.1f);

	Ogre::ColourValue lColour1(1.0f, 1.0f, 1.0f);
	Ogre::ColourValue lColour2(1.0f, 1.0f, 1.0f);
	Ogre::ColourValue lColour3(1.0f, 1.0f, 1.0f);
	Ogre::Light* pLight1 = pSceneManager->createLight();
	pLight1->setType(Ogre::Light::LT_SPOTLIGHT);
	pLight1->setPosition(30.0f, 30.0f, 30.0f);
	pLight1->setDirection(-1.0f, -1.0f, -1.0f);
	pLight1->setSpotlightRange(Ogre::Degree(30), Ogre::Degree(50));
	pLight1->setDiffuseColour(lColour1 * 0.5f);
	Ogre::Light* pLight2 = pSceneManager->createLight();
	pLight2->setType(Ogre::Light::LT_SPOTLIGHT);
	pLight2->setPosition(-30.0f, 30.0f, 30.0f);
	pLight2->setDirection(1.0f, -1.0f, -1.0f);
	pLight2->setSpotlightRange(Ogre::Degree(30), Ogre::Degree(50));
	pLight2->setDiffuseColour(lColour2 * 0.5f);
	Ogre::Light* pLight3 = pSceneManager->createLight();
	pLight3->setType(Ogre::Light::LT_SPOTLIGHT);
	pLight3->setPosition(30.0f, -30.0f, 30.0f);
	pLight3->setDirection(-1.0f, 1.0f, -1.0f);
	pLight3->setSpotlightRange(Ogre::Degree(30), Ogre::Degree(50));
	pLight3->setDiffuseColour(lColour3 * 0.5f);

	Ogre::Overlay* pMenuOverlay = Ogre::OverlayManager::getSingleton().create("Menu");
	Ogre::OverlayElement* pMenu = Ogre::OverlayManager::getSingleton().createOverlayElement("Panel", "Menu");
    pMenu->setMetricsMode(Ogre::GMM_PIXELS);
    pMenu->setWidth(200);
    pMenu->setHeight(200);
    pMenu->setTop(30);
    pMenu->setLeft(30);
    pMenu->setMaterialName("Examples/BumpyMetal");
	if (pMenu->isContainer()) pMenuOverlay->add2D(static_cast<Ogre::OverlayContainer*>(pMenu));
	pMenuOverlay->show();

	pOgre->startRendering();
}

int main(int argc, char **argv)
{
#ifdef WIN32
	// Maximize the console window
	typedef HWND (WINAPI *GetConsoleWindowFn)(void);
	HMODULE l_kernel32_h = GetModuleHandleA("kernel32.dll");
	GetConsoleWindowFn GetConsoleWindow = (GetConsoleWindowFn)GetProcAddress(l_kernel32_h, "GetConsoleWindow");
	if(GetConsoleWindow != 0) ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SetConsoleTitleA(" Heart|Dockyard");
#endif

	testing::InitGoogleTest(&argc, argv);
	if (RUN_ALL_TESTS() != 0) return 1;

	test();

	return 0;
}
