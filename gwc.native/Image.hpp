//
// :.:.:.:.:.
// GWC.Native
// v0.5.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Image.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_IMAGE_HPP
#define GWC_IMAGE_HPP

#ifdef __cplusplus

#include "header.hpp"

#pragma warning(disable: 4251)

namespace gwc
{
    /*
        =====
        Image
        =====

        La classe 'gImage' ha lo scopo di facilitare il
        caricamento di immagini e gestirne il ciclo vita.

        DESCRIZIONE
        -----------

        Il caricamento delle immagini è affidato a GDI32 e/o
        GDI+. Quest'ultimo DEVE ESSERE inizializzato tramite
        il metodo 'Render::init()'.

        Per nascondere i dettagli del backend utilizzato il
        riferimento all'HANDLE dell'immagine è anonimizzato
        tramite il tipo 'NativeImage'.

        'ImageHelper' è l'unica classe che può accedere
        all'HANDLE ospitato da 'gImage'.

        L'HANDLE è un puntatore condiviso.
    */

    typedef shared_ptr<void> NativeImage;

    class ImageHelper;

    class GWC_CPP_API gImage sealed
    {

    public:

        friend class ImageHelper;

        gImage (const char* path);
        gImage (const wchar_t* path);
        gImage (const string& path);
        gImage (const wstring& path);
        gImage ();
        ~gImage();

        bool load  (const char* path);
        bool load  (const wchar_t* path);
        bool load  (const string& path);
        bool load  (const wstring& path);
        void unload();

        bool isLoaded  () const;
        bool isUnloaded() const;

    private:

        NativeImage image;

    };
}

#pragma warning(default: 4251)

#endif // __cplusplus

#endif // !GWC_IMAGE_HPP
