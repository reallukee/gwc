//
// :.:.:.:.:.
// GWC.Native
// v0.5.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Icon.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_ICON_HPP
#define GWC_ICON_HPP

#ifdef __cplusplus

#include "header.hpp"

#pragma warning(disable: 4251)

namespace gwc
{
    /*
        ====
        Icon
        ====

        La classe 'gIcon' ha lo scopo di facilitare il
        caricamento di icone e gestirne il ciclo vita.

        DESCRIZIONE
        -----------

        Il caricamento delle icone è affidato a GDI32 e/o
        GDI+. Quest'ultimo DEVE ESSERE inizializzato tramite
        il metodo 'Render::init()'.

        Per nascondere i dettagli del backend utilizzato il
        riferimento all'HANDLE dell'icona è anonimizzato
        tramite il tipo 'NativeIcon'.

        'IconHelper' è l'unica classe che può accedere
        all'HANDLE ospitato da 'gIcon'.

        L'HANDLE è un puntatore condiviso.
    */

    typedef shared_ptr<void> NativeIcon;

    class IconHelper;

    class GWC_CPP_API gIcon sealed
    {

    public:

        friend class IconHelper;

        gIcon (const char* path);
        gIcon (const wchar_t* path);
        gIcon (const string& path);
        gIcon (const wstring& path);
        gIcon ();
        ~gIcon();

        bool load  (const char* path);
        bool load  (const wchar_t* path);
        bool load  (const string& path);
        bool load  (const wstring& path);
        void unload();

        bool isLoaded  () const;
        bool isUnloaded() const;

    private:

        NativeIcon icon;

    };
}

#pragma warning(default: 4251)

#endif // __cplusplus

#endif // !GWC_ICON_HPP
