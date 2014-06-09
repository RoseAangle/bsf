#pragma once

#include "BsGLPrerequisites.h"
#include "BsGLRenderSystem.h"
#include "BsRenderWindow.h"

namespace BansheeEngine
{
	class BS_RSGL_EXPORT GLSupport
	{
	public:
		GLSupport() { }
		virtual ~GLSupport() { }

		virtual RenderWindowPtr newWindow(RENDER_WINDOW_DESC& desc, RenderWindowPtr parentWindow) = 0;

		/**
		* Start anything special
		*/
		virtual void start() = 0;

		/**
		* Stop anything special
		*/
		virtual void stop() = 0;

		/**
		* Get vendor information
		*/
		const String& getGLVendor() const
		{
			return mVendor;
		}

		/**
		* Get version information
		*/
		const String& getGLVersion() const
		{
			return mVersion;
		}

		/**
		* Compare GL version numbers
		*/
		bool checkMinGLVersion(const String& v) const;

		/**
		* Check if an extension is available
		*/
		virtual bool checkExtension(const String& ext) const;

		/**
		* Get the address of a function
		*/
		virtual void* getProcAddress(const String& procname) = 0;

		/** Initialises GL extensions, must be done AFTER the GL context has been
			established.
		*/
		virtual void initializeExtensions();

		/**
		 * @brief	Gets a structure describing all available video modes.
		 */
		virtual VideoModeInfoPtr getVideoModeInfo() const = 0;

	protected:
		Set<String> extensionList;

		String mVersion;
		String mVendor;
	};
};